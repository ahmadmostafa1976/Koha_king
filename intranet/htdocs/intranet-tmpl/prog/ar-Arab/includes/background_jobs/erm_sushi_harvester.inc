[% USE Koha %]
[% USE raw %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="dialog message">
 [% IF job.status == 'finished' %]
 <table id="finishedtable">
 <tr>
 <td>مقدم خدمة بيانات الاستخدام</td>
 <td><a href="/cgi-bin/koha/erm/eusage/usage_data_providers/[% report.ud_provider_id | uri %]" title="قم بزيارة مقدم خدمة بيانات الاستخدام">[% report.ud_provider_name | html %]</a></td>
 </tr>
 <tr>
 <td>نوع التقرير</td>
 <td>[% report.report_type | html %]</td>
 </tr>
 <tr>
 <td>تمت معالجة صفوف التقرير</td>
 <td>[% job.progress | html %]</td>
 </tr>
 <tr>
 [% IF report.report_type.match( '^PR' ) %]
 <td>تمت إضافة المنصات</td>
 [% ELSIF report.report_type.match( '^DR' ) %]
 <td>تمت إضافة قواعد البيانات</td>
 [% ELSIF report.report_type.match( '^IR' ) %]
 <td>تمت إضافة المواد</td>
 [% ELSIF report.report_type.match( '^TR' ) %]
 <td>تمت إضافة العناوين</td>
 [% END %]
 <td>[% report.us_report_info.added_usage_objects | html %]</td>
 </tr>
 <tr>
 <td>تم تخطي الاستخدام الشهري</td>
 <td>[% report.us_report_info.skipped_mus | html %]</td>
 </tr>
 <tr>
 <td>تمت إضافة بيانات الاستخدام الشهري</td>
 <td>[% report.us_report_info.added_mus | html %]</td>
 </tr>
 <tr>
 <td>تم تخطي الاستخدام السنوي</td>
 <td>[% report.us_report_info.skipped_yus | html %]</td>
 </tr>
 <tr>
 <td>تمت إضافة بيانات الاستخدام السنوي</td>
 <td>[% report.us_report_info.added_yus | html %]</td>
 </tr>
 </table>
 [% ELSIF job.status == 'started' %]
 <p id="jobactionlabel"></p>
 [% ELSIF job.status == 'failed' %]
 <table id="finishedtable">
 <tr>
 <td>مقدم خدمة بيانات الاستخدام</td>
 <td><a href="/cgi-bin/koha/erm/eusage/usage_data_providers/[% report.ud_provider_id | uri %]" id="failed_provider_name" title="قم بزيارة مقدم خدمة بيانات الاستخدام"></a></td>
 </tr>
 <tr>
 <td>نوع التقرير</td>
 <td id="failed_report_type"></td>
 </tr>
 </table>
 [% END %]
 [% IF job.status != 'finished' %]
 [% INCLUDE "job_progress.inc" job_id=job.id %]
 [% END %]
 [% IF job.status == 'cancelled' %]
 <p>تم إلغاء المهمة قبل انتهائها.</p>
 [% END %]
 </div>
 [% END %]
[% END %]

[% Asset.js("js/job_progress.js") | $raw %]

[% BLOCK detail %]
 [% FOR m IN job.messages %]
 <div class="dialog message">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa fa-warning warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% SWITCH m.code %]
 [% CASE 'object_already_exists' %]
 <span><strong>[% m.title | html %]</strong> موجود بالفعل في مقدم خدمة البيانات هذا ولم يتم إنشاؤه. تم التحقق من إحصائيات الاستخدام الجديدة على أي حال</span>
 [% CASE 'object_added' %]
 <span><strong>[% m.title | html %]</strong> تمت الإضافة بنجاح</span>
 [% CASE 'object_could_not_be_added' %]
 <span><strong>[% m.title | html %]</strong> تعذرت المعالجة - يرجى التحقق من السجلات</span>
 [% CASE 'payload_too_large' %]
 <span>يتجاوز حجم ملف تقرير COUNTER الحد الذي حددته قاعدة البيانات. الحد هو [% m.message | html %] ميجابايت.</span><br>
 <span>يرجى زيادة هذا الحد أو حصاد فترة أقصر.</span>
 [% CASE 'no_items' %]
 <span>لم تعيد استجابة سوشي أي مواد.</span><br>
 <span>يرجى محاولة فترة حصاد مختلفة.</span>
 [% CASE %]
 <span>قام سوشي بإعادة: [% m.message | html %] [% m.code | html %]</span>
 [% END %]
 </div>
 [% END %]
[% END %]
 [% Asset.js("js/job_progress.js") | $raw %]

[% BLOCK js %]
 [% INCLUDE 'str/job_progress.inc' job_id=job.id %]
 [% INCLUDE 'str/erm_sushi_harvester.inc' %]
<script>
        $(document).ready(function(){
            let job_id = [% job.id | $raw %];
            updateProgress(job_id, {
                progress_callback : function(){
                    $.getJSON('/api/v1/jobs/'+job_id, function(job){
                        if(job.progress == 0){
                            $('#jobactionlabel').text(REQUESTING_SUSHI);
                        }else if(job.progress >= 1){
                            $('#jobactionlabel').text(CREATING_COUNTER);
                        }
                    });
                },
                finish_callback : function(){
                    $.getJSON('/api/v1/jobs/'+job_id, function(job){
                        if(!$('#finishedtable').length){
                            window.location.reload();
                        }
                    });
                }
            });

            let job_data = [% job.data | $raw %];
            let report_type = job_data.report_type;
            let ud_provider_name = job_data.ud_provider_name;
            $('#failed_report_type').text(report_type);
            $('#failed_provider_name').text(ud_provider_name);
        });

</script>
[% END %]
