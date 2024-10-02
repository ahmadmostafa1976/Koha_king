<div id="mana_share_report" class="modal" tabindex="-1" role="dialog" aria-labelledby="mana_share_modal_label">
 <div class="modal-dialog modal-wide" role="document">
 <div class="modal-content">
 <form method="post" id="mana_share_form" action="/cgi-bin/koha/reports/guided_reports.pl">
 [% INCLUDE 'csrf-token.inc' %]
 <div class="modal-header">
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button"><span aria-hidden="true">&times;</span></button>
 <h3 id="mana_share_modal_label">مشاركة مع مانا</h3>
 </div>
 <div class="modal-body">
 [% IF (mana_id) %]
 <div class="dialog alert">
 <p>تم ربط تقريرك بالفعل بتقرير مانا. شاركه إذا قمت بإجراء تعديلات، وإلا فلن يقوم بأي شيء.</p>
 </div>
 [% END %]
 <div id="note-error" class="dialog alert" role="alert">
 يرجى إدخال اسم االتقرير وملاحظة الوصف قبل المشاركة (الحد الأدنى 20 حرفًا) </div>
 <div class="shared_infos rows">
 <ul>
 <li><span class="label">المعرّف: </span><div id="shared_id"></div></li>
 <li><span class="label">الاسم: </span><div id="shared_name"></div></li>
 <li><span class="label">SQL: </span><div id="shared_sql"></div></li>
 <li><span class="label">المجموعة: </span><div id="shared_group"></div></li>
 <li><span class="label">نوع: </span><div id="shared_type"></div></li>
 <li><span class="label">ملاحظات: </span><div id="shared_notes"></div></li>
 [% IF (languages_loop) %]
 <li>
 <input type="hidden" name="op" value="cud-share">
 <label for="mana_language">اللغة:</label>
 <select id="mana_language" name="mana_language">
 [% FOREACH languages_loo IN languages_loop %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.plural ) %]
 [% FOREACH sublanguages_loo IN languages_loo.sublanguages_loop %]
 [% IF ( sublanguages_loo.enabled ) %]
 [% IF ( sublanguages_loo.sublanguage_current ) %]
 <option value="[% languages_loo.rfc4646_subtag | html %]" selected="selected">
 [% sublanguages_loo.native_description | html %]
 [% sublanguages_loo.script_description | html %]
 [% sublanguages_loo.region_description | html %]

 [% sublanguages_loo.variant_description | html %]
 ([% sublanguages_loo.rfc4646_subtag | html %])
 </option>
 [% ELSE %]
 <option value="[% languages_loo.rfc4646_subtag | html %]">
 [% sublanguages_loo.native_description | html %]
 [% sublanguages_loo.script_description | html %]
 [% sublanguages_loo.region_description | html %]
 [% sublanguages_loo.variant_description | html %]
 ([% sublanguages_loo.rfc4646_subtag | html %])
 </option>
 [% END %]
 [% END %]
 [% END %]
 [% ELSE %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.current ) %]
 <option value="[% languages_loo.rfc4646_subtag | html %]" selected="selected">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </option>
 [% ELSE %]
 <option value="[% languages_loo.rfc4646_subtag | html %]">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </option>
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 </select>
 </li>
 [% ELSE %]
 <input type="hidden" name="mana_language" value="[% lang | html %]" />
 [% END %]
 </ul>
 </div> <!-- /.shared_infos rows -->
 </div> <!-- /.modal-body -->
 <div class="modal-footer">
 <input type="hidden" id="reportid" name="reportid"/>
 <button id="ManaShareButton" type="submit" class="btn btn-default shared_infos">مشاركة</button>
 <button class="btn btn-default" id="ManaCloseButton" data-dismiss="modal" aria-hidden="true">إلغاء</button>
 </div>
 </form> <!-- /#mana_share_form -->
 </div> <!-- /.modal-content -->
 </div> <!-- /.modal-dialog -->
</div> <!-- /#mana_share_report -->
