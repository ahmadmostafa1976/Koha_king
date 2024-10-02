[%- BLOCK main_permissions -%]
 [% SWITCH name %]
 [%- CASE 'superlibrarian' -%]
 <span class="main_permission superlibrarian_permission">الوصول إلى كل وظائف المكتبي</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'circulate' -%]
 <span class="main_permission circulate_permission">إعارة المواد وردها</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'catalogue' -%]
 <span class="main_permission catalogue_permission">وصول الموظفين، يتيح عرض الفهرس في برنامج العميل</span>
 <span class="permissioncode">([% name | html %])</span> <span class="required">مطلوب لتسجيل دخول الموظفين.</span>
 [%- CASE 'parameters' -%]
 <span class="main_permission parameters_permission">إدارة إعدادات نظام كوها (لوحة الإدارة)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'borrowers' -%]
 <span class="main_permission borrowers_permission">إضافة، تعديل وعرض معلومات المستفيد</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'permissions' -%]
 <span class="main_permission permissions_permission">قم بضبط صلاحيات المستخدم</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reserveforothers' -%]
 <span class="main_permission reserveforothers_permission">وضع وتعديل الحجوزات للمستفيدين</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'editcatalogue' -%]
 <span class="main_permission editcatalogue_permission">تحرير الفهرس (تعديل البيانات الببليوغرافية/ المقتنيات)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'updatecharges' -%]
 <span class="main_permission updatecharges_permission">إدارة رسوم وغرامات المستفيدين</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'acquisition' -%]
 <span class="main_permission acquisition_permission">إدارة التزويد</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions' -%]
 <span class="main_permission suggestions_permission">إدارة المقترحات</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'tools' -%]
 <span class="main_permission tools_permission">استخدم كل الأدوات (توسيع لصلاحيات الأدوات الجزيئية)</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'editauthorities' -%]
 <span class="main_permission editauthorities_permission">تحرير الاستنادات</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'serials' -%]
 <span class="main_permission serials_permission">إدارة اشتراكات الدوريات</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reports' -%]
 <span class="main_permission reports_permission">السماح بالوصول إلى نظام التقارير الفرعي</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'staffaccess' -%]
 <span class="main_permission staffaccess_permission">السماح للموظفين بتعديل الصلاحيات، أسماء المستخدم، وكلمات المرور للموظفين الآخرين</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'coursereserves' -%]
 <span class="main_permission coursereserves_permission">الحجز الأكاديمي</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'plugins' -%]
 <span class="main_permission plugins_permission">برامج كوها المساعدة</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'lists' -%]
 <span class="main_permission lists_permission">قوائم</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'clubs' -%]
 <span class="main_permission clubs_permission">أندية المستفيد</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'ill' -%]
 <span class="main_permission ill_permission">إنشاء وتعديل طلبات الإعارة بين المكتبات</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'self_check' -%]
 <span class="main_permission self_check_permission">أنظمة الإعارة والرد الذاتية الفرعية</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'stockrotation' -%]
 <span class="main_permission self_check_permission">إدارة عمليات تدوير المخزون</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'cash_management' -%]
 <span class="main_permission cash_management_permission">إدارة النقد</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'problem_reports' -%]
 <span class="main_permission problem_reports_permission">إدارة تقارير مشكلات الأوباك</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'recalls' -%]
 <span class="main_permission recalls_permission">الاستدعاءات</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'erm' -%]
 <span class="main_permission erm_permission">أدر نظام الموارد الإلكترونية الفرعي</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'loggedinlibrary' -%]
 <span class="main_permission loggedinlibrary_permission">السماح للموظفين بتغيير المكتبة المسجل منها الدخول</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'preservation' -%]
 <span class="main_permission preservation_permission">أدر نظام الحفظ الفرعي</span>
 <span class="permissioncode">([% name | html %])</span>
 [%- END -%]
[%- END -%]

[%- BLOCK sub_permissions -%]
 [% SWITCH name %]
 [%- CASE 'circulate_remaining_permissions' -%]
 <span class="sub_permission circulate_remaining_permissions_subpermission">
 صلاحيات الإعارة المتبقية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'force_checkout' -%]
 <span class="sub_permission force_checkout_subpermission">
 قسر الإعارة عند وجود حد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_restrictions' -%]
 <span class="sub_permission manage_restrictions_subpermission">
 إدارة القيود على الحسابات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'overdues_report' -%]
 <span class="sub_permission overdues_report_subpermission">
 تنفيذ تقرير المواد المتأخرة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'override_renewals' -%]
 <span class="sub_permission override_renewals_subpermission">
 تخطي التجديدات المحظورة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_bookings' %]
 <span class="sub_permission manage_bookings_subpermission">
 إدارة حجوزات المواد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_checkout_notes' %]
 <span class="sub_permission manage_checkout_notes_subpermission">
 وضع إشارة تمت رؤيته/لم تتم رؤيته على ملاحظات الإعارة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_accounts' -%]
 <span class="sub_permission manage_accounts_subpermission">
 إدارة أنواع الأرصدة الدائنة والمدينة للحساب </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules' -%]
 <span class="sub_permission manage_circ_rules_subpermission">
 إدارة قواعد الإعارة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules_from_any_libraries' -%]
 <span class="sub_permission manage_circ_rules_from_any_libraries_subpermission">
 إدارة قواعد الإعارة من أي مكتبة. عند عدم ضبطها، يمكن للمستخدم مسجّل الدخول تحرير قواعد الإعارة لمكتبته فقط (يرجى ملاحظة أن manage_circ_rules لا يزال مطلوبًا) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'parameters_remaining_permissions' -%]
 <span class="sub_permission parameters_remaining_permissions_subpermission">
 صلاحيات ضوابط النظام المتبقية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_circ_rules' -%]
 <span class="sub_permission manage_circ_rules_subpermission">
 إدارة قواعد الإعارة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_sysprefs' -%]
 <span class="sub_permission manage_sysprefs_subpermission">
 أدر تفضيلات النظام </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_libraries' -%]
 <span class="sub_permission manage_libraries_subpermission">
 إدارة المكتبات ومجموعات المكتبات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_itemtypes' -%]
 <span class="sub_permission manage_itemtypes_subpermission">
 إدارة أنواع المادة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_auth_values' -%]
 <span class="sub_permission manage_auth_values_subpermission">
 إدارة فئات قيم الاستناد وقيم الاستناد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_categories' -%]
 <span class="sub_permission manage_patron_categories_subpermission">
 إدارة فئات المستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_restrictions' -%]
 <span class="sub_permission manage_patron_restrictions_subpermission">
 أدر قيود المستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_attributes' -%]
 <span class="sub_permission manage_patron_attributes_subpermission">
 إدارة سمات المستفيد الموسعة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_transfers' -%]
 <span class="sub_permission manage_transfers_subpermission">
 إدارة حدود نقل المكتبة ومصفوفة تكاليف النقل </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_circ_alerts' -%]
 <span class="sub_permission manage_item_circ_alerts_subpermission">
 إدارة تنبيهات إعارة المادة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_cities' -%]
 <span class="sub_permission manage_cities_subpermission">
 إدارة المدن والبلدان </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_marc_frameworks' -%]
 <span class="sub_permission manage_marc_frameworks_subpermission">
 إدارة إطارات مارك الببليوغرافية والاستنادية واختبرها </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_classifications' -%]
 <span class="sub_permission manage_classifications_subpermission">
 إدارة مصادر التصنيف وقواعد التسجيل </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_matching_rules' -%]
 <span class="sub_permission manage_matching_rules_subpermission">
 إدارة قواعد مطابقة التسجيلة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_oai_sets' -%]
 <span class="sub_permission manage_oai_sets_subpermission">
 إدارة مجموعات OAI </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_search_fields' -%]
 <span class="sub_permission manage_item_search_fields_subpermission">
 إدارة حقول بحث المادة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_filters' -%]
 <span class="sub_permission manage_search_filters_subpermission">
 أدر منقحات البحث المحفوظة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_engine_config' -%]
 <span class="sub_permission manage_search_engine_config_subpermission">
 إدارة تهيئة محرك البحث </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_marc_overlay_rules' -%]
 <span class="sub_permission manage_marc_overlay_rules_subpermission">
 أدر تهيئة قواعد تراكب مارك </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_search_targets' -%]
 <span class="sub_permission manage_search_targets_subpermission">
 إدارة تهيئة خادم Z39.50 وSRU </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_didyoumean' -%]
 <span class="sub_permission manage_didyoumean_subpermission">
 إدارة تهيئة هل تعني؟ </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_smtp_servers' -%]
 <span class="sub_permission manage_manage_smtp_servers_subpermission">
 إدارة خوادم SMTP </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_column_config' -%]
 <span class="sub_permission manage_column_config_subpermission">
 إدارة تهيئة العمود </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_audio_alerts' -%]
 <span class="sub_permission manage_audio_alerts_subpermission">
 إدارة التنبيهات الصوتية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_additional_fields' -%]
 <span class="sub_permission manage_aditional_fields_subpermission">
 Manage additional fields (requires the corresponding permission, one of edit_subscription, order_manage, edit_invoices, or remaining_permissions under updatecharges)
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_sms_providers' -%]
 <span class="sub_permission manage_sms_providers_subpermission">
 إدارة مقدمي خدمة الرسائل النصية القصيرة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_usage_stats' -%]
 <span class="sub_permission manage_usage_stats_subpermission">
 إدارة إعدادات إحصائيات الاستخدام </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_mana' -%]
 <span class="sub_permission manage_mana_subpermission">
 إدارة مشاركة محتوى قاعدة معرفة مانا </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_keyboard_shortcuts' -%]
 <span class="sub_permission manage_keyboard_shortcuts_subpermission">
 إدارة اختصارات لوحة المفاتيح لمحرر الفهرسة المتقدم </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_background_jobs' -%]
 <span class="sub_permission manage_background_jobs_subpermission">
 إدارة مهام الخلفية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_curbside_pickups' -%]
 <span class="sub_permission manage_curbside_pickups_subpermission">
 أدر الالتقاطات الجانبية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_borrowers' -%]
 <span class="sub_permission delete_borrowers_subpermission">
 حذف المستفيدين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_borrowers' -%]
 <span class="sub_permission edit_borrowers_subpermission">
 إضافة، تعديل وعرض معلومات المستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'list_borrowers' -%]
 <span class="sub_permission list_borrowers_subpermission">
 بحث، قائمة، وعرض المستفيدين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'view_borrower_infos_from_any_libraries' -%]
 <span class="sub_permission view_borrower_infos_from_any_libraries_subpermission">
 عرض معلومات المستفيد من أي مكتبة. إذا لم يتم الضبط، يمكن للمستفيد مسجل الدخول الوصول إلى معلومات المستفيد من مكتبته أو مجموعة مكتباته فقط. </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'send_messages_to_borrowers' -%]
 <span class="sub_permission send_messages_to_borrowers_subpermission">
 Send messages to patrons
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'modify_holds_priority' -%]
 <span class="sub_permission modify_holds_priority_subpermission">
 تعديل أولوية الحجوزات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'place_holds' -%]
 <span class="sub_permission place_holds_subpermission">
 وضع حجوزات للمستفيدين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_all_items' -%]
 <span class="sub_permission delete_all_items_subpermission">
 حذف جميع المواد مرة واحدة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_catalogue' -%]
 <span class="sub_permission edit_catalogue_subpermission">
 تحرير الفهرس (تعديل البيانات الببليوغرافية/ المقتنيات) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_locked_records' -%]
 <span class="sub_permission edit_locked_records_subpermission">
 Edit locked records
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'set_record_sources' -%]
 <span class="sub_permission set_record_sources_subpermission">
 Set record source
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'advanced_editor' -%]
 <span class="sub_permission advanced_editor_subpermission">
 استخدم محرر الفهرسة السريعة (يتطلب edit_catalogue) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_shared_macros' -%]
 <span class="sub_permission create_shared_macros_subpermission">
 إنشاء ماكرو جديدة (تتطلب advanced_editor) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_shared_macros' -%]
 <span class="sub_permission delete_shared_macros_subpermission">
 حذف ماكرو مشتركة (تتطلب advanced_editor) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_items' -%]
 <span class="sub_permission edit_items_subpermission">
 تحرير المواد (لا يشمل المواد المقيدة بواسطة مجموعة المكتبة) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_any_item' -%]
 <span class="sub_permission edit_items_subpermission">
 تحرير أي مادة بما في ذلك المواد التي قد تكون مقيدة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_items_restricted' -%]
 <span class="sub_permission edit_items_restricted_subpermission">
 قم بقصر تعديل المواد على الحقول الفرعية المعرفة في تفضيل النظام SubfieldsToAllowForRestrictedEditing (يرجى ملاحظة أن edit_item لا يزال مطلوبًا) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'fast_cataloging' -%]
 <span class="sub_permission fast_cataloging_subpermission">
 الفهرسة السريعة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_groups' -%]
 <span class="sub_permission manage_item_groups_subpermission">
 إنشاء، وتحديث، وحذف مجموعات مواد وإضافة وإزالة مواد من مجموعة مواد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_item_editor_templates' -%]
 <span class="sub_permission manage_item_editor_templates_subpermission">
 إنشاء وتحديث وحذف قوالب محرر المواد المملوكة للآخرين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'remaining_permissions' -%]
 <span class="sub_permission remaining_permissions_subpermission">
 الصلاحيات المتبقية لإدارة الغرامات والرسوم </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'discount' -%]
 <span class="sub_permission discount_subpermission">
 خصم الأرصدة المدينة للمستفيدين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'payout' -%]
 <span class="sub_permission payout_subpermission">
 اعتمادات الدفع للمستفيدين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'refund' -%]
 <span class="sub_permission refund_subpermission">
 رد المبالغ المدفوعة إلى المستفيدين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'writeoff' -%]
 <span class="sub_permission writeoff_subpermission">
 شطب الرسوم والغرامات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manual_invoice' -%]
 <span class="sub_permission manual_invoice_subpermission">
 إضافة فواتير يدوية إلى حساب المستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manual_credit' -%]
 <span class="sub_permission manual_credit_subpermission">
 إضافة اعتمادات يدوية إلى حساب المستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'suggestions_manage' -%]
 <span class="sub_permission suggestions_manage_subpermission">
 إدارة مقترحات الشراء </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_add_del' -%]
 <span class="sub_permission budget_add_del_subpermission">
 إضافة وحذف التمويلات (لكن لا يمكنك تعديل التمويلات) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_manage' -%]
 <span class="sub_permission budget_manage_subpermission">
 إدارة التمويلات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_manage_all' -%]
 <span class="sub_permission budget_manage_all_subpermission">
 إدارة كل التمويلات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'budget_modify' -%]
 <span class="sub_permission budget_modify_subpermission">
 تعديل التمويلات ( لا يمكن إنشاء سطور، لكن يمكن تعديل السطور الموجودة) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'contracts_manage' -%]
 <span class="sub_permission contracts_manage_subpermission">
 إدارة العقود </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'group_manage' -%]
 <span class="sub_permission group_manage_subpermission">
 إدارة مجموعات السلة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_manage' -%]
 <span class="sub_permission order_manage_subpermission">
 إدارة السلة وسطور الطلبية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_manage_all' -%]
 <span class="sub_permission order_manage_all_subpermission">
 إدارة كل السلات وسطور الطلبيات، بغض النظر على القيود الموجودة عليها </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'issue_manage' -%]
 <span class="sub_permission issue_manage_subpermission">
 إدارة مشكلات المزودين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'order_receive' -%]
 <span class="sub_permission order_receive_subpermission">
 استلام الطلبيات وإدارة الشحنات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'period_manage' -%]
 <span class="sub_permission period_manage_subpermission">
 إدارة الميزانيات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'planning_manage' -%]
 <span class="sub_permission planning_manage_subpermission">
 إدارة تخطيطات الميزانية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'vendors_manage' -%]
 <span class="sub_permission vendors_manage_subpermission">
 إدارة المزودين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'currencies_manage' -%]
 <span class="sub_permission currencies_manage_subpermission">
 إدارة العملات وأسعار الصرف </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'batch_upload_patron_images' -%]
 <span class="sub_permission batch_upload_patron_images_subpermission">
 تحميل صور المستفيد بالدفعة أو واحدة تلو الأخرى </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_anonymize_patrons' -%]
 <span class="sub_permission delete_anonymize_patrons_subpermission">
 حذف المستعيرين القدامي وعدم تعريف هوية سجل الإعارة (حذف سجل قراءة المستعير) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'batch_extend_due_dates' -%]
 <span class="sub_permission batch_extend_due_dates_subpermission">
 إجراء تمديد لتواريخ الاستحقاق بالدفعة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_calendar' -%]
 <span class="sub_permission edit_calendar_subpermission">
 قم بتعريف أيام غلق المكتبة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_additional_contents' -%]
 <span class="sub_permission edit_additional_contents_subpermission">
 قم بكتابة محتويات إضافية للأوباك وواجهات الموظف (الأخبار وتخصيصات HTML) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_notice_status_triggers' -%]
 <span class="sub_permission edit_notice_status_triggers_subpermission">
 ضبط محفزات الحالة/الإخطارات للمواد المتأخرة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_notices' -%]
 <span class="sub_permission edit_notices_subpermission">
 تعريف الإخطارات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_patrons' -%]
 <span class="sub_permission edit_patrons_subpermission">
 إجراء تعديلات بالدفعة على المستفيدين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_quotes' -%]
 <span class="sub_permission edit_quotes_subpermission">
 محرر الاقتباسات لخاصية اقتباس اليوم </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'export_catalog' -%]
 <span class="sub_permission export_catalog_subpermission">
 تصدير البيانات الببليوغرافية وبيانات المقتنيات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'import_patrons' -%]
 <span class="sub_permission import_patrons_subpermission">
 استيراد بيانات المستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'inventory' -%]
 <span class="sub_permission inventory_subpermission">
 قم بإجراء جرد لفهرسك </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchdel' -%]
 <span class="sub_permission items_batchdel_subpermission">
 إجراء حذف للمواد بالدفعة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchmod' -%]
 <span class="sub_permission items_batchmod_subpermission">
 إجراء تعديل المواد بالدفعة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'items_batchmod_restricted' -%]
 <span class="sub_permission items_batchmod_restricted_subpermission">
 قم بقصر تعديل المواد بالدفعة على الحقول الفرعية المعرفة في تفضيل النظام SubfieldsToAllowForRestrictedBatchmod  (يرجى ملاحظة أن items_batchmod لا يزال مطلوبًا) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'label_creator' -%]
 <span class="sub_permission label_creator_subpermission">
 إنشاء ملصقات كعب وباركود صالحة للطباعة من بيانات الفهرس والمستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_csv_profiles' -%]
 <span class="sub_permission manage_csv_profiles_subpermission">
 إدارة أوضاع تصدير CSV </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_patron_lists' -%]
 <span class="sub_permission manage_patron_lists_subpermission">
 إضافة، تحرير وحذف قوائم المستفيدين ومحتوياتها </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_staged_marc' -%]
 <span class="sub_permission manage_staged_marc_subpermission">
 أدر تسجيلات مارك المجهزة، بما في ذلك استكمال وعكس الاستيرادات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'marc_modification_templates' -%]
 <span class="sub_permission marc_modification_templates_subpermission">
 إدارة قوالب تعديل مارك </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'moderate_comments' -%]
 <span class="sub_permission moderate_comments_subpermission">
 مراقبة تعليقات المستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'moderate_tags' -%]
 <span class="sub_permission moderate_tags_subpermission">
 مراقبة وسوم المستفيد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'records_batchdel' -%]
 <span class="sub_permission records_batchdel_subpermission">
 إجراء حذف للتسجيلات بالدفعة (الببليوغرافية أو الاستنادية) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'records_batchmod' -%]
 <span class="sub_permission records_batchmod_subpermission">
 إجراء تعديل بالدفعة على التسجيلات (الببليوغرافية أو الاستنادات) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'rotating_collections' -%]
 <span class="sub_permission rotating_collections_subpermission">
 إدارة مجموعات التدوير </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'schedule_tasks' -%]
 <span class="sub_permission schedule_tasks_subpermission">
 جدولة المهام للتشغيل </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'stage_marc_import' -%]
 <span class="sub_permission stage_marc_import_subpermission">
 تجهيز تسجيلات مارك في المستودع </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_local_cover_images' -%]
 <span class="sub_permission upload_local_cover_images_subpermission">
 تحميل صور الغلاف المحلية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'view_system_logs' -%]
 <span class="sub_permission view_system_logs_subpermission">
 استعراض سجلات النظام </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'check_expiration' -%]
 <span class="sub_permission check_expiration_subpermission">
 تحقق من انتهاء الدورية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'claim_serials' -%]
 <span class="sub_permission claim_serials_subpermission">
 مطالبة الدوريات المفقودة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_subscription' -%]
 <span class="sub_permission create_subscription_subpermission">
 إنشاء اشتراك جديد </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_subscription' -%]
 <span class="sub_permission delete_subscription_subpermission">
 حذف اشتراك حالي </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_subscription' -%]
 <span class="sub_permission edit_subscription_subpermission">
 تحرير اشتراك حالي </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'receive_serials' -%]
 <span class="sub_permission receive_serials_subpermission">
 استلام الدوريات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'renew_subscription' -%]
 <span class="sub_permission renew_subscription_subpermission">
 تجديد اشتراك </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'routing' -%]
 <span class="sub_permission routing_subpermission">
 تمرير </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'superserials' -%]
 <span class="sub_permission superserials_subpermission">
 إدارة الاشتراكات من أي فرع (ينطبق فقط عند استخدام IndependentBranches ) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_reports' -%]
 <span class="sub_permission delete_reports_subpermission">
 حذف تقارير SQL </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'create_reports' -%]
 <span class="sub_permission create_reports_subpermission">
 إنشاء تقارير SQL </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'execute_reports' -%]
 <span class="sub_permission execute_reports_subpermission">
 تنفيذ تقارير SQL </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'add_reserves' -%]
 <span class="sub_permission add_reserves_subpermission">
 إضافة حجز أكاديمي </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_reserves' -%]
 <span class="sub_permission delete_reserves_subpermission">
 حذف الحجز الأكاديمي </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_courses' -%]
 <span class="sub_permission manage_courses_subpermission">
 إضافة، تحرير وحذف الدورات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'configure' -%]
 <span class="sub_permission configure_subpermission">
 تهيئة البرامج المساعدة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage' -%]
 <span class="sub_permission manage_subpermission">
 إدارة البرامج المساعدة (تثبيت/ إلغاء تثبيت) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'report' -%]
 <span class="sub_permission report_subpermission">
 استخدم برامج التقارير المساعدة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'tool' -%]
 <span class="sub_permission tool_subpermission">
 استخدم برامج الأدوات المساعدة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'admin' -%]
 <span class="sub_permission admin_subpermission">
 Use administrative plugins
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_public_lists' -%]
 <span class="sub_permission delete_public_lists_subpermission">
 حذف القوائم العامة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_public_lists' -%]
 <span class="sub_permission edit_public_lists_subpermission">
 تحرير القوائم العامة (الاسم، الإعدادات، والصلاحيات، ولكن ليس المحتويات الصريحة) </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_public_list_contents' -%]
 <span class="sub_permission edit_public_list_contents_subpermission">
 تحرير محتويات القوائم العامة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_general_files' -%]
 <span class="sub_permission upload_general_files_subpermission">
 تحميل أي ملف </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'upload_manage' -%]
 <span class="sub_permission upload_manage_subpermission">
 إدارة الملفات المرفوعة (<em>إلا بدون upload_general_files</em>)
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'access_files' -%]
 <span class="sub_permission access_files_subpermission">
 الوصول إلى الملفات المخزنة في الخادم </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_clubs' -%]
 <span class="sub_permission edit_clubs_subpermission">
 إنشاء الأندية وتحريرها </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_templates' -%]
 <span class="sub_permission edit_templates_subpermission">
 إنشاء قوالب النادي وتحريرها </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'enroll' -%]
 <span class="sub_permission enroll_subpermission">
 اشتراك المستفيدين في الأندية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edi_manage' -%]
 <span class="sub_permission edi_manage_subpermission">
 إدارة إرسالات EDIFACT </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'reopen_closed_invoices' -%]
 <span class="sub_permission reopen_closed_invoices_subpermission">
 إعادة فتح الفواتير المغلقة </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'edit_invoices' -%]
 <span class="sub_permission edit_invoices_subpermission">
 تحرير الفواتير </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_invoices' -%]
 <span class="sub_permission delete_invoices_subpermission">
 حذف الفواتير </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'merge_invoices' -%]
 <span class="sub_permission merge_invoices_subpermission">
 دمج الفواتير </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'delete_baskets' -%]
 <span class="sub_permission delete_baskets_subpermission">
 حذف السلال </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# self_check %]
 [%- CASE 'self_checkin_module' -%]
 <span class="sub_permission self_checkin_module_subpermission">
 تسجيل الدخول إلى نظام الرد الذاتي الفرعي. ملاحظة: هذه الصلاحية تمنع المستفيد من استخدام أي وظيفة أخرى من وظائف الأوباك </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'self_checkout_module' -%]
 <span class="sub_permission self_checkout_module_subpermission">
 قم بإجراء الإعارة الذاتية في الأوباك. يجب استخدامه للمستفيد الذي يطابق AutoSelfCheckID </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_rota_items' -%]
 <span class="sub_permission manage_rota_items_subpermission">
 إضافة المواد وإزالتها من اللوائح </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'manage_rotas' -%]
 <span class="sub_permission manage_rotas_subpermission">
 إنشاء، تحرير وحذف اللوائح </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# cash_management %]
 [%- CASE 'manage_cash_registers' -%]
 <span class="sub_permission manage_cash_registers_subpermission">
 إضافة، أو تحرير وأرشفة السجلات النقدية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'takepayment' -%]
 <span class="sub_permission takepayment_subpermission">
 قم بالوصول إلى نقطة صفحة البيع وتحصيل المدفوعات </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'cashup' -%]
 <span class="sub_permission cashup_subpermission">
 تنفيذ إجراء دفع نقدي بواسطة سجل نقدي </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- CASE 'anonymous_refund' -%]
 <span class="sub_permission anonymous_refund_subpermission">
 تنفيذ إجراءات رد أموال بدون تعريف هوية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# problem_reports %]
 [%- CASE 'manage_problem_reports' -%]
 <span class="sub_permission manage_problem_reports_subpermission">
 إدارة تقارير مشكلات الأوباك </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# recalls %]
 [%- CASE 'manage_recalls' -%]
 <span class="sub_permission place_recalls_subpermission">
 إدارة الاستدعاءات للمستفيدين </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# identity_providers %]
 [%- CASE 'manage_identity_providers' -%]
 <span class="sub_permission manage_identity_providers_subpermission">
 أدر موفري الهوية </span>
 <span class="permissioncode">([% name | html %])</span>
 [%# record_sources %]
 [%- CASE 'manage_record_sources' -%]
 <span class="sub_permission manage_record_sources_subpermission">
 Manage record sources
 </span>
 <span class="permissioncode">([% name | html %])</span>
 [%- END -%]
[%- END -%]
