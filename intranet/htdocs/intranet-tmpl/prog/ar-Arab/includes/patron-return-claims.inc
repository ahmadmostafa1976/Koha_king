<p id="return-claims-controls">
 [% IF ( patron.return_claims.resolved.count > 0 || patron.return_claims.unresolved.count > 0 ) %]
 <a id="show_all_claims" class="ctrl_link" href="#">عرض كل  [% patron.return_claims.count | html %] المطالبات</a>
 <a id="show_unresolved_claims" class="ctrl_link disabled" href="#">عرض [% patron.return_claims.unresolved.count | html %]  مطالبة غير محلولة</a>
 [% ELSE %]
 <a id="show_all_claims" class="ctrl_link" href="#"></a>
 <a id="show_unresolved_claims" class="ctrl_link disabled" href="#"></a>
 [% END %]
</p>
<table id="return-claims-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="return-claim-id">معرف المطالبة</th>
 <th class="return-claim-id">محلولة؟</th>
 <th class="return-claim-record-title anti-the">عنوان</th>
 <th class="return-claim-notes">ملاحظات</th>
 <th class="return-claim-created-on">تم إنشاؤه في</th>
 <th class="return-claim-created-on">تم إنشاؤه في</th>
 <th class="return-claim-updated-on">تم التحديث في</th>
 <th class="return-claim-updated-on">تم التحديث في</th>
 <th class="return-claim-resolution">الدقة</th>
 <th class="return-claim-actions NoSort">&nbsp;</th>
 </tr>
 </thead>
</table>
