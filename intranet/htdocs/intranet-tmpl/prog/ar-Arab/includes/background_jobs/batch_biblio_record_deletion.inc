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
 [% SWITCH m.code %]
 [% CASE 'biblio_not_exists' %]
 <span>الرقم الببليوغرافي [% m.biblionumber | html %] غير موجود في قاعدة البيانات.</span>
 [% CASE 'item_issued' %]
 <span>مادة واحدة على الأقل معارة في التسجيلة الببليوغرافية [% m.biblionumber | html %].</span>
 [% CASE 'reserve_not_cancelled' %]
 <span>لم يتم حذف التسجيلة الببليوغرافية [% m.biblionumber | html %]. تعذر إلغاء الحجز (reserve_id [% m.reserve_id | html %]).</span>
 [% CASE 'item_not_deleted' %]
 <span>لم يتم حذف التسجيلة الببليوغرافية [% m.biblionumber | html %]. حدث خطأ أثناء حذف المادة (itemnumber [% m.itemnumber | html %]).</span>
 [% CASE 'biblio_not_deleted' %]
 <span>لم يتم حذف التسجيلة الببليوغرافية [% m.biblionumber | html %]. حدث خطأ.</span>
 [% CASE 'biblio_deleted' %]
 <span>تم حذف التسجيلة الببليوغرافية [% m.biblionumber | html %] بنجاح.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
