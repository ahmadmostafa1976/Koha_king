[% USE Koha %]

<div id="navmenu">
<div id="navmenulist">

 [% IF ( CAN_user_parameters_manage_sysprefs ) %]
 <h5>تفضيلات النظام</h5>
 <ul>
 <li><a href="/cgi-bin/koha/admin/preferences.pl">تفضيلات النظام</a></li>
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_libraries || CAN_user_parameters_manage_itemtypes || CAN_user_parameters_manage_auth_values ) %]
 <h5>اﻹعدادات الأساسية</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_libraries ) %]
 <li><a href="/cgi-bin/koha/admin/branches.pl">المكتبات</a></li>
 <li><a href="/cgi-bin/koha/admin/library_groups.pl">مجموعات المكتبة</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_itemtypes ) %]
 <li><a href="/cgi-bin/koha/admin/itemtypes.pl">أنواع المادة</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_auth_values ) %]
 <li><a href="/cgi-bin/koha/admin/authorised_values.pl">قيم الاستناد</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_patron_categories || CAN_user_parameters_manage_circ_rules || CAN_user_parameters_manage_patron_attributes || CAN_user_parameters_manage_transfers || CAN_user_parameters_manage_item_circ_alerts || CAN_user_parameters_manage_cities || CAN_user_parameters_manage_curbside_pickups || CAN_user_parameters_manage_patron_restrictions ) %]
 <h5>المستفيدين والإعارة</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_patron_categories ) %]
 <li><a href="/cgi-bin/koha/admin/categories.pl">فئات المستفيد</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_circ_rules ) %]
 <li><a href="/cgi-bin/koha/admin/smart-rules.pl">قواعد الإعارة والغرامات</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_patron_attributes ) %]
 <li><a href="/cgi-bin/koha/admin/patron-attr-types.pl">أنواع سمات المستفيدين</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_transfers ) %]
 <li><a href="/cgi-bin/koha/admin/branch_transfer_limits.pl">حدود النقل بالمكتبة</a></li>
 <li><a href="/cgi-bin/koha/admin/transport-cost-matrix.pl">مصفوفة تكاليف النقل</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_item_circ_alerts ) %]
 <li><a href="/cgi-bin/koha/admin/item_circulation_alerts.pl">تنبيهات إعارة المادة</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCirculationDesks') && CAN_user_parameters_manage_libraries ) %]
 <li><a href="/cgi-bin/koha/admin/desks.pl">مكاتب</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_cities ) %]
 <li><a href="/cgi-bin/koha/admin/cities.pl">مدن وبلدان</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_curbside_pickups ) %]
 <li><a href="/cgi-bin/koha/admin/curbside_pickup.pl">التقاط جانبي</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_patron_restrictions ) %]
 <li><a href="/cgi-bin/koha/admin/restrictions.pl">أنواع قيود المستفيد</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_accounts || ( Koha.Preference('UseCashRegisters') && CAN_user_parameters_manage_cash_registers ) ) %]
 <h5>الحسابات</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_accounts ) %]
 <li><a href="/cgi-bin/koha/admin/debit_types.pl">أنواع حساب المدين</a></li>
 <li><a href="/cgi-bin/koha/admin/credit_types.pl">أنواع حساب الدائن</a></li>
 [% END %]
 [% IF ( Koha.Preference('UseCashRegisters') && CAN_user_parameters_manage_cash_registers ) %]
 <li><a href="/cgi-bin/koha/admin/cash_registers.pl">سجلات نقدية</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF CAN_user_plugins && plugins_enabled %]
 <h5>برامج مساعدة</h5>
 <ul>
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl">برامج مساعدة</a></li>
 </ul>
 [% END %]

 [% IF CAN_user_parameters_manage_background_jobs %]
 <h5>مهام</h5>
 <ul>
 <li><a href="/cgi-bin/koha/admin/background_jobs.pl">مهام</a></li>
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_marc_frameworks || CAN_user_parameters_manage_classifications || CAN_user_parameters_manage_matching_rules || CAN_user_parameters_manage_oai_sets || CAN_user_parameters_manage_item_search_fields || CAN_user_parameters_manage_search_engine_config || CAN_user_parameters_manage_marc_overlay_rules || ( Koha.Preference('SavedSearchFilters') && CAN_user_parameters_manage_search_filters ) ) %]
 <h5>الفهرس</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_marc_frameworks ) %]
 <li><a href="/cgi-bin/koha/admin/biblio_framework.pl">إطار مارك الببليوغرافي</a></li>
 <li><a href="/cgi-bin/koha/admin/koha2marclinks.pl">تخطيط كوها إلى مارك</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_marc_frameworks ) %]
 <li><a href="/cgi-bin/koha/admin/checkmarc.pl">اختبار إطار مارك الببليوغرافي</a></li>
 <li><a href="/cgi-bin/koha/admin/authtypes.pl">انواع الاستناد</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_classifications ) %]
 <li><a href="/cgi-bin/koha/admin/classsources.pl">تهيئة التصنيف</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_matching_rules ) %]
 <li><a href="/cgi-bin/koha/admin/matching-rules.pl">قواعد مطابقة التسجيلة</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_record_sources ) %]
 <li><a href="/cgi-bin/koha/admin/record_sources">Record sources</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_marc_overlay_rules ) %]
 <li><a href="/cgi-bin/koha/admin/marc-overlay-rules.pl">قواعد تراكب التسجيلة</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_oai_sets ) %]
 <li><a href="/cgi-bin/koha/admin/oai_sets.pl">تهيئة مجموعات OAI</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_item_search_fields ) %]
 <li><a href="/cgi-bin/koha/admin/items_search_fields.pl">حقول بحث المواد</a></li>
 [% END %]
 [% IF ( Koha.Preference('SavedSearchFilters') && CAN_user_parameters_manage_search_filters ) %]
 <li><a href="/cgi-bin/koha/admin/search_filters.pl">منقحات البحث</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_search_engine_config ) %]
 <li><a href="/cgi-bin/koha/admin/searchengine/elasticsearch/mappings.pl">تهيئة محرك البحث (Elasticsearch)</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_acquisition_currencies_manage || CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) ) %]
 <h5>إعدادات التزويد</h5>
 <ul>
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">العملات وأسعار الصرف</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">الميزانيات</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">التمويلات</a></li>
 [% END %]
 [% IF ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">حسابات EDI</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">المكتبة EANs</a></li>
 [% END %]
 </ul>
 [% END %]

 [% IF ( CAN_user_parameters_manage_identity_providers || CAN_user_parameters_manage_smtp_servers || CAN_user_parameters_manage_search_targets || CAN_user_parameters_manage_didyoumean || CAN_user_parameters_manage_column_config || CAN_user_parameters_manage_audio_alerts || ( CAN_user_parameters_manage_sms_providers && Koha.Preference('SMSSendDriver') == 'Email' ) || CAN_user_parameters_manage_usage_stats || CAN_user_parameters_manage_additional_fields || ( Koha.Preference('EnableAdvancedCatalogingEditor') && CAN_user_parameters_manage_keyboard_shortcuts ) ) %]
 <h5>عوامل إضافية</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_identity_providers) %]
 <li><a href="/cgi-bin/koha/admin/identity_providers.pl">موفرى الهوية</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_search_targets ) %]
 <li><a href="/cgi-bin/koha/admin/z3950servers.pl">خوادم Z39.50/SRU</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_smtp_servers ) %]
 <li><a href="/cgi-bin/koha/admin/smtp_servers.pl">خوادم SMTP</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_didyoumean ) %]
 <li><a href="/cgi-bin/koha/admin/didyoumean.pl">هل تعني؟</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_column_config ) %]
 <li><a href="/cgi-bin/koha/admin/columns_settings.pl">إعدادات الجدول</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_audio_alerts ) %]
 <li><a href="/cgi-bin/koha/admin/audio_alerts.pl">تنبيهات صوتية</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_sms_providers && Koha.Preference('SMSSendDriver') == 'Email' ) %]
 <li><a href="/cgi-bin/koha/admin/sms_providers.pl">مقدمي خدمة الرسائل النصية القصيرة</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_usage_stats ) %]
 <li><a href="/cgi-bin/koha/admin/usage_statistics.pl">مشاركة إحصائيات الاستخدام</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_mana ) %]
 <li><a href="/cgi-bin/koha/admin/share_content.pl">مشاركة المحتوى مع قاعدة معرفة مانا</a></li>
 [% END %]
 [% IF ( CAN_user_parameters_manage_additional_fields ) %]
 <li><a href="/cgi-bin/koha/admin/additional-fields.pl">حقول إضافية</a></li>
 [% END %]
 [% IF ( Koha.Preference('EnableAdvancedCatalogingEditor') && CAN_user_parameters_manage_keyboard_shortcuts ) %]
 <li><a href="/cgi-bin/koha/admin/adveditorshortcuts.pl">اختصارات لوحة المفاتيح</a></li>
 [% END %]
 [% IF Koha.Preference('ILLModule ') && CAN_user_ill %]
 <li><a href="/cgi-bin/koha/admin/ill_batch_statuses.pl">حالات دفعة الإعارة البينية</a></li>
 [% END %]
 </ul>
 [% END %]
</div>
</div>
