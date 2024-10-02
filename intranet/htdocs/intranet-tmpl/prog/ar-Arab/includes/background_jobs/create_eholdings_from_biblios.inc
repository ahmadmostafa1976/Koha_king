[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report && job.status != 'started' && job.status != 'new' %]
 [% IF report.total_records == report.total_success %]
 <div class="dialog message">
 تم إنشاء كل عناوين المقتنيات الإلكترونية بنجاح! </div>
 [% ELSIF report.total_success == 0 %]
 <div class="dialog message">
 لم يتم إنشاء أي عناوين مقتنيات إلكترونية. لقد حدث خطأ. </div>
 [% ELSE %]
 <div class="dialog message">
 [% report.total_success | html %] / [% report.total_records | html %] تم إنشاء عناوين المقتنيات الإلكترونية بنجاح بكن حدثت بعض الأخطاء. </div>
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
 [% CASE 'package_do_not_exist' %]
 <span>الحزمة #[% m.package_id | html %] غير موجودة.</span>
 [% CASE 'biblio_already_exists' %]
 <span>التسجيلة الببليوغرافية ([% m.biblio_id | html %]) موجودة بالفعل في هذه الحزمة (<a href="/cgi-bin/koha/erm/eholdings/local/resources/[% m.resource_id | uri %]">المورد #[% m.resource_id | html %]</a>)</span>
 [% CASE 'eholding_not_created' %]
 <span>لا يمكن إنشاء عنوان المقتنيات الإلكترونية من التسجيلة الببليوغرافية #[% m.biblio_id | html %]،واجهت الخطأ التالي: [% m.error | html %].</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
