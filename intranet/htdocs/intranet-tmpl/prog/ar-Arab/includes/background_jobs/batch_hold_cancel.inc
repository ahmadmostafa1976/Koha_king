[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_holds == report.total_success %]
 <div class="dialog message">
 تم إلغاء كل الحجوزات بنجاح! </div>
 [% ELSE %]
 <div class="dialog message">
 <span>[% report.total_success | html %] / [% report.total_holds | html %] حجزاً تم تعديله بنجاح. لكن حدثت بعض الأخطاء.</span>
 [% IF job.status == 'cancelled' %]<span>تم إلغاء المهمة قبل انتهائها.</span>[% END %]
 </div>
 [% END %]
 [% END %]

[% END %]

[% BLOCK detail %]
 [% FOR m IN report_messages %]
 <div class="dialog message">
 [% IF m.type == 'success' %]
 <i class="fa fa-check success"></i>
 [% ELSIF m.type == 'warning' %]
 <i class="fa-solid fa-triangle-exclamation warn"></i>
 [% ELSIF m.type == 'error' %]
 <i class="fa fa-exclamation error"></i>
 [% END %]
 [% SWITCH m.code %]
 [% CASE 'hold_not_cancelled' %]
 [% IF m.biblio && m.patron %]
 <span>حجز على <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% m.biblio.biblionumber | uri %]">[% m.biblio.title | html %]</a> لـ <a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% m.patron.borrowernumber | uri %]">[% INCLUDE 'patron-title.inc' patron=m.patron %]</a> لم يتم إلغاؤها.</span>
 [% END %]
 <span>حدث خطأ أثناء الإلغاء.</span>
 [% SWITCH m.error %]
 [% CASE 'hold_not_found' %]
 <span>لم يتم العثور على حجز بالمعرّف [% m.hold_id | html %].</span>
 [% CASE %]<span>خطأ غير معروف '[% m.error | html %]'.</span>
 [% END %]
 [% CASE 'hold_cancelled' %]
 [% biblio_link = BLOCK %]<a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% m.biblio_id | uri %]">[% m.biblio.title | html %]</a>[% END %]
 [% patron_link = BLOCK %]<a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% m.patron_id | uri %]">[% INCLUDE 'patron-title.inc' patron=m.patron %]</a>[% END %]
 <span>تم إلغاء الحجز على [% biblio_link | $raw | $KohaSpan %] لـ [% patron_link | $raw | $KohaSpan %] بنجاح.</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
