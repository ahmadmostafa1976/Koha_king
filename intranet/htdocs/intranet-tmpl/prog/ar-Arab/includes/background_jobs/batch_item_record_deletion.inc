[% USE KohaSpan %]
[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="dialog message">
 [% IF report.deleted_itemnumbers.size %]
 <p>[% report.deleted_itemnumbers.size | html %] مادة تم حذفها.</p>
 [% IF report.deleted_biblionumbers.size %]
 <p>[% report.deleted_biblionumbers.size | html %] تسجيلة تم حذفها.</p>
 [% END %]
 [% ELSE %]
 <p>لم يتم حذف مواد.</p>
 [% END %]
 </div>

 [% IF report.not_deleted_itemnumbers.size %]
 <div class="dialog error">
 [% report.not_deleted_itemnumbers.size | html %] تعذر حذف المواد: [% FOREACH not_deleted_itemnumber IN report.not_deleted_itemnumbers %][% not_deleted_itemnumber | html %][% END %] </div>
 [% END %]

 [% IF job.status == 'cancelled' %]
 <div class="dialog error">
 <span>تم إلغاء المهمة قبل انتهائها.</span>
 <a href="/cgi-bin/koha/tools/batchMod.pl" title="تعديل مستفيدين بالدفعة جديد">تعديل مستفيدين بالدفعة جديد</a>
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
 [% SWITCH m.code %]
 [% CASE 'item_not_deleted' %]
 [% item_link = BLOCK %]<a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% m.biblionumber | uri %]&itemnumber=[% m.itemnumber | uri %]">[% m.barcode | html %]</a>[% END %]
 <span>لا يمكن المادة ذات الباركود [% item_link | $raw | $KohaSpan%] :</span>
 [% SWITCH m.reason %]
 [% CASE "book_on_loan" %]<span>المادة معارة</span>
 [% CASE "not_same_branch" %]<span>لا تنتمي المادة إلى مكتبتك</span>
 [% CASE "book_reserved" %]<span>للمادة حجز في الانتظار</span>
 [% CASE "linked_analytics" %]<span>للمادة تحليلات مرتبطة</span>
 [% CASE "last_item_for_hold" %]<span>آخر مادة للتسجيلة الببليوغرافية ذات الحجز على المستوى الببليوغرافي</span>
 [% CASE %]<span>سبب غير معروف '[% m.reason | html %]'</span>
 [% END %]
 [% CASE %]<span>رسالة غير معروفة '[% m.code | html %]'</span>
 [% END %]
 </div>
 [% END %]
[% END %]

[% BLOCK js %]
[% END %]
