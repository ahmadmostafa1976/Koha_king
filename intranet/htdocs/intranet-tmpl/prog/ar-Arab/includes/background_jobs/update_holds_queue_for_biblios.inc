[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF report.total_biblios == report.total_success %]
 <div class="dialog message">
 تم تحديث صف الحجوزات بنجاح. </div>
 [% ELSE %]
 <div class="dialog message">
 <span>تم تحديث صف الحجوزات لـ [% report.total_success | html %] / [% report.total_biblios | html %]  بنجاح. حدثت بعض الأخطاء.</span>
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
 [% CASE 'holds_queue_update_error' %]
 [% IF m.biblio_id %]
 <span>صف الحجوزات للتسجيلة الببليوغرافية <a href="/cgi-bin/koha/catalogue/detail.pl?biblionumber=[% m.biblio_id | uri %]">[% m.biblio.title | html %]</a>.</span>
 [% END %]
 <span>لقد حدث خطأ  ([% m.error | html %])</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
