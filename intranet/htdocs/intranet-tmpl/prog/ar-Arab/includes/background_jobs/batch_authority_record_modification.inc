[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="dialog message">
 تم تعديل جميع التسجيلات بنجاح! <a href="/cgi-bin/koha/tools/batch_record_modification.pl" title="تعديل جديد لدفعة التسجيلات">تعديل جديد لدفعة التسجيلات</a>
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
 [% authority_link = BLOCK %]<a href="/cgi-bin/koha/authorities/detail.pl?authid=[% m.authid | uri %]">[% m.authid | html %]</a>[% END %]
 [% SWITCH m.code %]
 [% CASE 'authority_not_modified' %]
 <span>لم يتم تعديل تسجيلة الاستناد [% authority_link | $raw | $KohaSpan %]. حدث خطأ أثناء تعديلها</span>
 [% IF m.error %] ([% m.error | html %])[% END %].
 [% CASE 'authority_modified' %]
 <span>تم تعديل تسجيلة الاستناد [% authority_link | $raw | $KohaSpan %] بنجاح.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
