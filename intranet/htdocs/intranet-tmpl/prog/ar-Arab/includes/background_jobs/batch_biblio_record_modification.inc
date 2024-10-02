[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="dialog message">
 <span>تم تعديل جميع التسجيلات بنجاح!</span>
 <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="تعديل جديد لدفعة التسجيلات">تعديل جديد لدفعة التسجيلات</a>
 [% IF lists.count %]
 <br />
 <span>إضافة تسجيلات معدلة إلى القائمة التالية:</span>
 <select name="add_bibs_to_list" id="add_bibs_to_list">
 <option value="">حدد قائمة</option>
 [% FOREACH list IN lists %]
 <option class="shelf" value="[% list.shelfnumber | html %]">[% list.shelfname | html %]</option>
 [% END %]
 </select>
 [% END %]
 </div>
 [% ELSE %]
 <div class="dialog message">
 <span>تم تعديل [% report.total_success | html %] / [% report.total_records | html %] تسجيلة بنجاح. لكن حدثت بعض الأخطاء.</span>
 [% IF job.status == 'cancelled' %]<span>تم إلغاء المهمة قبل انتهائها.</span>[% END %]
 <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="تعديل جديد لدفعة التسجيلات">تعديل جديد لدفعة التسجيلات</a>
 </div>
 [% END %]
 [% END %]
[% END %]

[% BLOCK detail %]
 [% FOR m IN job.messages %]
 <div class="dialog message">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa-solid fa-triangle-exclamation warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% biblio_link = BLOCK %]<a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% m.biblionumber | uri %]">[% m.biblionumber | html %]</a>[% END %]
 [% SWITCH m.code %]
 [% CASE 'biblio_not_modified' %]
 <span>لم يتم تعديل التسجيلة الببليوغرافية [% biblio_link | $raw %]. حدث خطأ أثناء تعديلها.</span>
 [% IF m.error %] ([% m.error | html %])[% END %].
 [% CASE 'biblio_modified' %]
 <span>تم تعديل التسجيلة الببليوغرافية [% biblio_link | $raw %] بنجاح.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
 <script>
        $("#add_bibs_to_list").change(function(){
            var selected = $("#add_bibs_to_list").find("option:selected");
            if ( selected.attr("class") == "shelf" ){
                var shelfnumber = selected.val();
                var bibs = new Array();
                [% FOREACH message IN job.messages %]
                    [% IF message.code == 'biblio_modified' %]
                        bibs.push("biblionumber="+[% message.biblionumber | html %]);
                    [% END %]
                [% END %]
                var bibstring = bibs.join("&");
                window.open('/cgi-bin/koha/virtualshelves/addbybiblionumber.pl?shelfnumber='+shelfnumber+'&confirm=1&'+bibstring, 'popup', 'width=500,height=500,toolbar=false,scrollbars=yes,resizable=yes');
                return false;
            }
        });
    </script>
[% END %]
