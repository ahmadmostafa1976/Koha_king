<div id="toolbar" class="btn-toolbar">
 [% IF ( CAN_user_reports_create_reports ) %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> تقرير جديد <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li id="newmenuc"><a href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form">تقرير موجه جديد</a> </li>
 <li id="newsql"><a href="/cgi-bin/koha/reports/guided_reports.pl?op=add_form_sql">قاعدة بينات جديدة</a> </li>
 [% IF Koha.Preference('Mana')==1 %]
 <li id="new_mana_sql"><a href="#" data-toggle="modal" data-target="#mana_search_result">SQL جديدة من مانا</a> </li>
 [% END %]
 </ul>
 </div>
 [% END %]

 [% IF ( showsql || execute || editsql || save_successful ) %]
 [% IF ( CAN_user_reports_delete_reports && !CAN_user_reports_create_reports ) %]
 <div class="btn-group">
 <form>
 <input type="hidden" name="op" value="cud-delete" />
 <input type="hidden" name="id" value="[% id | html %]" />
 <button type="submit" class="delete btn btn-default">
 <i class="fa fa-trash-can"></i> حذف </button>
 </form>
 </div>
 [% ELSE %]
 [% IF ( CAN_user_reports_create_reports || CAN_user_reports_delete_reports ) %]
 <div class="btn-group">
 <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true"
                        aria-expanded="false">
 <i class="fa-solid fa-pencil" aria-hidden="true"></i> تحرير <span class="caret"></span>
 </button>
 <ul class="dropdown-menu">
 [% IF ( CAN_user_reports_create_reports ) %]
 [% UNLESS ( editsql ) # Do not show edit button on edit page %]
 <li>
 <a id="editreport" href="/cgi-bin/koha/reports/guided_reports.pl?id=[% id | html %]&amp;op=edit_form">
 تحرير </a>
 </li>
 [% END %]
 <li>
 <a href="/cgi-bin/koha/reports/guided_reports.pl?op=duplicate&id=[% id | uri %]" title="نسخ هذا التقرير المحفوظ">
 تكرار </a>
 </li>
 [% END %]

 [% IF ( CAN_user_reports_delete_reports ) %]
 <li>
 <form method="post" action="/cgi-bin/koha/reports/guided_reports.pl">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete" />
 <input type="hidden" name="id" value="[% id | html %]" />
 </form>
 <a href="#" class="delete">حذف</button>
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
 [% END %]
 [% END %]

 [% IF ( showsql || execute || editsql || save_successful ) %]
 [% UNLESS ( errors ) # Unless there are errors saving a report %]
 <div class="btn-group">
 <a id="runreport" class="btn btn-default" href="/cgi-bin/koha/reports/guided_reports.pl?id=[% id | html %]&amp;op=run">
 <i class="fa fa-play"></i> تشغيل التقرير </a>
 </div>
 [% IF templates.count %]
 <div class="btn-group">
 <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true"
                    aria-expanded="false">
 <i class="fa fa-code"></i> تشغيل بالقالب <span class="caret"></span>
 </button>
 <ul class="dropdown-menu">
 [% FOREACH tmpl IN templates %]
 <li>
 <a id="runreport" href="/cgi-bin/koha/reports/guided_reports.pl?id=[% id | html %]&amp;op=run&amp;template=[% tmpl.id | html %][% PROCESS params %]">
 [% tmpl.name | html %]
 </a>
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
 <div class="btn-group">
 <a class="btn btn-default" href="/cgi-bin/koha/tools/scheduler.pl?id=[% id | html %]">
 <i class="fa-solid fa-clock"></i> جدول </a>
 </div>
 [% END %]

 [% IF ( mana_id && Koha.Preference('Mana') == 1 ) %]
 <div class="btn-group">
 <button class="btn btn-default btn-sm dropdown-toggle" data-toggle="dropdown"> التبليغ عن خطأ <span class="caret"></span></button>
 <ul class="dropdown-menu">
 [% FOREACH c IN mana_comments %]
 <li class="mana-comment" data-id="[% c.id | $raw %]">
 <a href="#">[% c.message | html %] ([% c.nb | html %])</a>
 </li>
 [% END %]
 <li role="separator" class="divider"></li>
 <li class="mana-other-comment"><a href="#">أخرى</a> </li>
 </ul>
 </div>

 <div id="mana-comment-box" class="modal" tabindex="-1" role="dialog" aria-labelledby="mana_search_result_label">
 <div class="modal-dialog modal-lg" role="document">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="إغلاق" class="close" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h3 id="mana_submit_comment">قم بإدخال تعليق جديد (الحد الأقصى 35 حرفًا)</h3>
 </div>
 <div class="modal-body">
 <input hidden="hidden" id="mana-resource" value="تقرير">
 <input hidden id="mana-resource-id" value="[% mana_id | $raw %]">
 <div>
 <input type="text" maxlength="35" size="35" id="mana-comment">
 </div>
 <button id="mana-send-comment"> التعليق </button>
 </div>
 </div>
 </div>
 </div>
 [% END %] [% IF ( execute ) %] [% BLOCK params %] [%- FOREACH param IN sql_params %]&amp;sql_params=[% param | uri %][% END %] [%- FOREACH param_name IN param_names %]&amp;param_name=[% param_name | uri %][% END %] [%- END %] <div class="btn-group">
 <button aria-haspopup="menu" aria-label="قم بتحديد التنسيق وتنزيل نتائج التقرير" class="btn btn-default dropdown-toggle" data-toggle="dropdown" id="format"><i class="fa fa-download"></i> تنزيل <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a id="csv" href="/cgi-bin/koha/reports/guided_reports.pl?op=export&amp;format=csv&amp;id=[% id | html %]&amp;reportname=[% name |uri %][% PROCESS params %]">[% PROCESS 'delimiter_text.inc' %]</a></li>
 <li><a id="tab" href="/cgi-bin/koha/reports/guided_reports.pl?op=export&amp;format=tab&amp;id=[% id | html %]&amp;reportname=[% name |uri %][% PROCESS params %]">نص التبويب المنفصل</a></li>
 <li><a id="ods" href="/cgi-bin/koha/reports/guided_reports.pl?op=export&amp;format=ods&amp;id=[% id | html %]&amp;reportname=[% name |uri %][% PROCESS params %]">فتح جدول بيانات المستند</a></li>
 [% IF processed_notice_title %]
 <li><a id="template" href="/cgi-bin/koha/reports/guided_reports.pl?op=export&amp;format=template&amp;id=[% id | html %]&amp;template=[% template_id | html %]&amp;reportname=[% name |uri %][% PROCESS params %]">القالب المعروض ([% processed_notice_title | html %])</a></li>
 [% END %]
 [% IF (results.json) %]
 <li><a id="download-chart" href="#">شكل بياني (.svg)</a></li>
 [% END %]
 </ul>
 </div>
 <div class="btn-group">
 <button type="button" id="toggle_sql" class="btn btn-default toggle_sql" data-complete-text="<i class='fa-solid fa-eye-slash'></i> [% t('Hide SQL code') | html %]" data-toggle="button" aria-pressed="false" autocomplete="off">
 <i class="fa-solid fa-eye"></i> إظهار رمز SQL </button>
 </div>
 <div class="btn-group">
 [% IF allresults.size %]
 <a class="btn btn-default" href="#" data-toggle="modal" data-target="#chartModal"><i class="fa fa-chart-bar"></i> إنشاء رسم بياني</a>
 [% ELSE %]
 <a class="btn btn-default" href="#" data-toggle="modal" data-target="#chartModal"><i class="fa fa-chart-bar"></i> إنشاء رسم بياني</a>
 <a class="btn btn-default fetch_chart_data" href="/cgi-bin/koha/reports/guided_reports.pl?id=[% id | html %]&amp;op=run&amp;reportname=[% name |uri %][% PROCESS params %]&amp;want_full_chart=1"><i class="fa fa-chart-bar"></i> الحصول على جميع البيانات للمخطط البياني</a>
 [% END %]

 </div>
 [% END %]

 [% END %]
</div>

[% IF Koha.Preference('Mana')==1 %]
 <div id="mana_search_result" class="modal" tabindex="-1" role="dialog" aria-labelledby="mana_search_result_label">
 <div class="modal-dialog modal-lg">
 <form method="get" id="mana_search_form">
 <div class="modal-content">
 <div class="modal-header">
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h3 id="mana_search_result_label">بحث مانا</h3>
 </div>
 <div class="modal-body">
 <div id="mana_search_failed" class="dialog alert mana_search_status" style="display:none">
 لا يمكن إتمام بحثك. يرجى إعادة المحاولة مرة أخرى. <div id="mana_search_errortext"></div>
 </div>
 <div id="mana_use_failed" class="dialog alert mana_search_status" style="display:none">
 لا يمكن استيراد هذا التقرير. يرجى إعادة المحاولة مرة أخرى لاحقًا. <div id="mana_use_errortext"></div>
 </div>
 <fieldset>
 <p>
 بحث التقارير بواسطة الكلمة المفتاحية: <input type="text" id="mana_search_field" />
 <input class="mana_search_button" type="submit" value="بحث" />
 <span id="mana-loading" style="display:none"> <img src="[% interface | html %]/[% theme | html %]/img/spinner-small.gif" alt="" /> جاري التحميل </span>
 </p>
 </fieldset>
 <div id="mana_result_content">
 </div>
 </div>
 <div class="modal-footer">
 <button type="button" class="btn btn-default" data-dismiss="modal">إلغاء</button>
 </div>
 </div>
 </form>
 </div>
 </div>
[% END %]
