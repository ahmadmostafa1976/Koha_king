[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_records == report.total_success %]
 <div class="dialog message">
 تم حذف كل التسجيلات بنجاح! </div>
 [% ELSIF report.total_success == 0 %]
 <div class="dialog message">
 لم يتم حذف أي تسجيلات. حدث خطأ. </div>
 [% ELSE %]
 <div class="dialog message">
 [% report.total_success | html %] / [% report.total_records | html %] تسجيلة تم حذفها بنجاح ولكن حدثت بعض الأخطاء. </div>
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
 [% IF m.code == 'authority_not_exists' %]
 <span>معرّف الاستناد [% m.authid | html %] غير موجود في قاعدة البيانات.</span>
 [% ELSIF m.code == 'authority_not_deleted' %]
 <span>لم يتم حذف تسجيلة الاستناد [% m.authid | html %]. حدث خطأ.</span>
 [% ELSIF m.code == 'authority_deleted' %]
 <span>تم حذف الاستناد [% m.authid | html %] بنجاح.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
