[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">تسجيلات مجهزة مكتملة</div>
 [% END %]

 <h2>نتائج تجهيز مارك</h2>
 [% SWITCH job.decoded_data.record_type %]
 [% CASE 'biblio' %]
 <h3>معالجة التسجيلات الببليوغرافية</h3>
 [% CASE 'auth' %]
 <h3>معالجة تسجيلات الاستناد</h3>
 [% END %]
 <ul>
 <li>[% report.total | html %]تسجيلة فى الملف</li>
 <li>[% report.import_errors | html %] تسجيلة غير مجهزة بسبب أخطاء مارك</li>
 <li>[% report.staged | html %] تسجيلة مجهزة</li>
 [% IF ( report.checked_matches ) %]
 <li>[% report.matched | html %] التسجيلات التي على الأقل تحتوي واحدة من قواعد المطابقة &quot;[% report.matcher_code | html %]&quot;</li>
 [% ELSE %]
 [% IF ( report.matcher_failed ) %]
 <li>فشل مطابقة التسجيلة -- تعذر استرجاع قاعدة المطابقة المحددة.</li>
 [% ELSE %]
 <li>لم يتم التحقق من وجود تطابقات للتسجيلات الحالية في الفهرس</li>
 [% END %]
 [% END %]
 [% IF report.record_type == 'biblio' %]
 <li>[% report.num_items | html %] تسجيلات المواد التي تم العثور عليها وتجهيزها</li>
 [% END %]
 [% IF ( report.label_batch ) %]
 <li>إنشاء دفعة تسميات جديدة: # [% report.label_batch | html %] </li>
 [% END %]
 </ul>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | uri %]">عرض الدفعة</a>
 </p>
 [% IF report.basket_id && report.vendor_id %]
 <p>
 <a id="addtobasket" class="btn btn-default" href="/cgi-bin/koha/acqui/addorderiso2709.pl?import_batch_id=[% report.import_batch_id | html %]&basketno=[% report.basket_id | html %]&booksellerid=[% report.vendor_id | html %]">إضافة ملفات مجهزة إلى السلة</a>
 </p>
 [% END %]
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
