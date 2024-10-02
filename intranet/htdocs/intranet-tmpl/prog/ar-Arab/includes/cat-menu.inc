[% USE Koha %]
<div id="navmenu">
 <div id="navmenulist">

 [% IF ( CAN_user_tools_stage_marc_import || CAN_user_tools_manage_staged_marc ) %]
 <h5>استيراد</h5>
 <ul>
 [% IF ( CAN_user_tools_stage_marc_import ) %]
 <li>
 <a href="/cgi-bin/koha/tools/stage-marc-import.pl">تجهيز تسجيلات للاستيراد</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_manage_staged_marc ) %]
 <li>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl">إدارة التسجيلات المجهزة</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_export_catalog ) %]
 <h5>تصدير</h5>
 <ul>
 [% IF ( CAN_user_tools_export_catalog ) %]
 <li>
 <a href="/cgi-bin/koha/tools/export.pl">تصدير بيانات الفهرس</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_inventory || ( ( Koha.Preference('OpacCatalogConcerns') || Koha.Preference('CatalogConcerns') ) && CAN_user_editcatalogue_edit_catalogue ) ) %]
 <h5>التقارير</h5>
 <ul>
 [% IF ( CAN_user_tools_inventory ) %]
 <li>
 <a href="/cgi-bin/koha/tools/inventory.pl">الجرد</a>
 </li>
 [% END %]
 [% IF ( Koha.Preference('OpacCatalogConcerns') || Koha.Preference('CatalogConcerns') ) && CAN_user_editcatalogue_edit_catalogue %]
 <li>
 <a href="/cgi-bin/koha/cataloguing/concerns.pl">شكاوى الفهرس</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_items_batchmod || CAN_user_tools_items_batchdel || CAN_user_tools_records_batchmod || CAN_user_tools_records_batchdel || CAN_user_tools_marc_modification_templates ) %]
 <h5>تحرير بالدفعة</h5>
 <ul>
 [% IF ( CAN_user_tools_items_batchmod ) %]
 <li>
 <a href="/cgi-bin/koha/tools/batchMod.pl">تعديل المواد بالدفعة</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_items_batchdel ) %]
 <li>
 <a href="/cgi-bin/koha/tools/batchMod.pl?del=1">حذف المواد بالدفعة</a>
 </li>
 [% END %]
 [% IF CAN_user_tools_records_batchmod %]
 <li>
 <a href="/cgi-bin/koha/tools/batch_record_modification.pl">تعديل التسجيلة بالدفعة</a>
 </li>
 [% END %]
 [% IF CAN_user_tools_records_batchdel %]
 <li>
 <a href="/cgi-bin/koha/tools/batch_delete_records.pl">حذف التسجيلات بالدفعة</a>
 </li>
 [% END %]
 [% IF ( CAN_user_tools_marc_modification_templates ) %]
 <li>
 <a href="/cgi-bin/koha/tools/marc_modification_templates.pl">قوالب تعديلات مارك</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_items_batchmod || ( CAN_user_stockrotation_manage_rotas && Koha.Preference('StockRotation') ) ) %]
 <h5>أتمتة</h5>
 <ul>
 [% IF ( CAN_user_tools_items_batchmod ) %]
 <li>
 <a href="/cgi-bin/koha/tools/automatic_item_modification_by_age.pl">تعديلات المادة حسب العمر</a>
 </li>
 [% END %]
 [% IF ( CAN_user_stockrotation_manage_rotas && Koha.Preference('StockRotation') ) %]
 <li>
 <a href="/cgi-bin/koha/tools/stockrotation.pl">تدوير المخزون</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_tools_label_creator || CAN_user_tools_upload_local_cover_images ) %]
 <h5>الأدوات</h5>
 <ul>
 [% IF ( CAN_user_tools_label_creator ) %]
 <li>
 <a href="/cgi-bin/koha/labels/label-home.pl">منشئ الملصقات</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/labels/barcode-print.pl">مولد صورة الباركود</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/labels/spinelabel-home.pl">منشئ ملصق الكعب السريع</a>
 </li>
 [% END %]

 [% IF ( CAN_user_tools_upload_local_cover_images ) %]
 <li>
 <a href="/cgi-bin/koha/tools/upload-cover-image.pl">تحميل صور غلاف محلية</a>
 </li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters ) %]
 <h5>الإدارة</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_sysprefs ) %]
 <li>
 <a class="circ-button" href="/cgi-bin/koha/admin/preferences.pl?tab=cataloguing">تفضيلات</a>
 </li>
 [% END %]
 <li>
 <a class="circ-button" href="/cgi-bin/koha/admin/admin-home.pl">التهيئة</a>
 </li>
 </ul>
 [% END %]

 </div>
</div>
