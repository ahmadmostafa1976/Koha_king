[% USE Koha %]

[% SET report = job.decoded_data %]
[% BLOCK report %]
 [% IF job.status == 'finished' %]
 [% IF report %]
 <div class="dialog message">
 تمت إعادة فهرسة [% report.record_ids.size | html %] تسجيلة بنجاح! </div>
 [% ELSE %]
 <div class="dialog message">
 تعذرت قراءة بيانات المهمة، راجع السجلات للتفاصيل </div>
 [% END %]
 [% ELSIF job.status == 'cancelled' %]
 <span>تم إلغاء المهمة قبل انتهائها.</span>
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
 [% END %] [% SWITCH m.code %] [% CASE 'index_error' %] لقد حدث خطأ ما أثناء عملية الفهرسة: [% m.error | html %] [% END %] </div>
 [% END %]
 [% IF report %]
 <h3> معرفات التسجيلة:</h3>
 <ul>
 [% FOREACH record_id IN report.record_ids %]
 <li><a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% record_id | uri %]">[% record_id | html %]</a></li>
 [% END %]
 </ul>
 [% END %]
[% END %]


[% BLOCK js %]
[% END %]
