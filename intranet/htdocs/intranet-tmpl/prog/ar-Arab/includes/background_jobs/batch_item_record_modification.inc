[% USE Koha %]
[% INCLUDE 'columns_settings.inc' %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 <div class="dialog message">
 [% IF report.modified_itemnumbers.size %]
 <span>[% report.modified_itemnumbers.size | html %] المواد المعدلة بـ [% report.modified_fields | html %] الحقول المعدلة.</span>
 [% ELSE %]
 <span>لم يتم تعديل مواد.</span>
 [% END %]

 [% IF job.status == 'cancelled' %]<span>تم إلغاء المهمة قبل انتهائها.</span>[% END %]
 <a href="/cgi-bin/koha/tools/batchMod.pl" title="تعديل مستفيدين بالدفعة جديد">تعديل مستفيدين بالدفعة جديد</a>
 </div>
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
 [% CASE %]<span>رسالة غير معروفة '[% m.code | html %]'</span>
 [% END %]
 </div>
 [% END %]

 [% IF too_many_items_display %]
 <p>عدد كبير جدًا من المواد ([% report.modified_itemnumbers.size | html %]): لقد قمت بتحرير أكثر من [% Koha.Preference('MaxItemsToDisplayForBatchMod') | html %] مادة بالدفعة، لن يتم عرض المواد.</p>
 [% ELSIF items.size %]
 [% PROCESS items_table_batchmod headers => item_header_loop, items => items, display_columns_selection => 1 %]
 [% END %]
[% END %]

[% BLOCK js %]
 [% Asset.js("js/pages/batchMod.js") | $raw %]
[% END %]
