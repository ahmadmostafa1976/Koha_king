[% USE Koha %]
[% USE Branches %]
[% USE Registers %]

<div id="navmenu">
 <div id="navmenulist">
 <ul>
 <li><a href="/cgi-bin/koha/tools/tools-home.pl">الصفحة الرئيسية للأدوات</a></li>
 </ul>
 [% IF ( CAN_user_tools_manage_patron_lists || CAN_user_clubs || CAN_user_tools_moderate_comments || CAN_user_tools_import_patrons  || CAN_user_tools_edit_notices || CAN_user_tools_edit_notice_status_triggers || CAN_user_tools_label_creator || CAN_user_tools_delete_anonymize_patrons  || CAN_user_tools_edit_patrons || CAN_user_tools_moderate_tags || ( CAN_user_tools_batch_upload_patron_images && Koha.Preference('patronimages') ) || CAN_user_tools_rotating_collections ) %]
 <h5>المستفيدين والإعارة</h5>
 <ul>
 [% IF ( CAN_user_tools_manage_patron_lists ) %]
 <li><a href="/cgi-bin/koha/patron_lists/lists.pl">قوائم المستفيد</a></li>
 [% END %]
 [% IF (CAN_user_clubs) %]
 <li><a href="/cgi-bin/koha/clubs/clubs.pl">أندية المستفيد</a></li>
 [% END %]
 [% IF ( CAN_user_tools_moderate_comments ) %]
 <li><a href="/cgi-bin/koha/reviews/reviewswaiting.pl">التعليقات</a></li>
 [% END %]
 [% IF ( CAN_user_tools_import_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/import_borrowers.pl">إستيراد مستفيدين</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_notices ) %]
 <li><a href="/cgi-bin/koha/tools/letter.pl">الإخطارات والكعوب</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_notice_status_triggers ) %]
 <li><a href="/cgi-bin/koha/tools/overduerules.pl">إخطار التأخير / محفزات الحالة</a></li>
 [% END %]
 [% IF ( CAN_user_tools_label_creator ) %]
 <li><a href="/cgi-bin/koha/patroncards/home.pl">منشئ بطاقات المستفيدين</a></li>
 [% END %]
 [% IF ( CAN_user_tools_delete_anonymize_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/cleanborrowers.pl">حذف وعدم تعريف هوية المستفيد بالدفعة</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_patrons ) %]
 <li><a href="/cgi-bin/koha/tools/modborrowers.pl">تعديل المستفيد بالدفعة</a></li>
 [% END %]
 [% IF ( CAN_user_tools_batch_extend_due_dates ) %]
 <li><a href="/cgi-bin/koha/tools/batch_extend_due_dates.pl">تمديد تواريخ الاستحقاق بالدفعة</a></li>
 [% END %]
 [% IF ( CAN_user_tools_moderate_tags ) %]
 <li><a href="/cgi-bin/koha/tags/review.pl">الوسوم</a></li>
 [% END %]
 [% IF ( CAN_user_tools_batch_upload_patron_images && Koha.Preference('patronimages') ) %]
 <li><a href="/cgi-bin/koha/tools/picture-upload.pl">تحميل صور مستفيد</a></li>
 [% END %]
 [% IF ( CAN_user_tools_rotating_collections ) %]
 <li><a href="/cgi-bin/koha/rotating_collections/rotatingCollections.pl">مجموعات التدوير</a></li>
 [% END %]
 </ul>
 [% END # /IF ( CAN_user_tools_items_batchdel... %]

 [% IF ( CAN_user_tools_edit_calendar || CAN_user_tools_manage_csv_profiles || CAN_user_tools_view_system_logs || CAN_user_tools_edit_additional_contents  || CAN_user_tools_schedule_tasks || CAN_user_tools_edit_quotes || ( Koha.ArePluginsEnabled() && CAN_user_plugins_tool )  || CAN_user_tools_upload_general_files || CAN_user_tools_access_files ) %]
 <h5>أدوات إضافية</h5>
 <ul>
 [% IF ( CAN_user_tools_edit_calendar ) %]
 <li><a href="/cgi-bin/koha/tools/holidays.pl">التقويم</a></li>
 [% END %]
 [% IF ( CAN_user_tools_manage_csv_profiles ) %]
 <li><a href="/cgi-bin/koha/tools/csv-profiles.pl">ملفات CSV</a></li>
 [% END %]
 [% IF ( CAN_user_tools_view_system_logs ) %]
 <li><a href="/cgi-bin/koha/tools/viewlog.pl">عارض السجل</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_additional_contents ) %]
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=news">أخبار</a></li>
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=html_customizations">تخصيصات HTML</a></li>
 <li><a href="/cgi-bin/koha/tools/additional-contents.pl?category=pages">صفحات</a></li>
 [% END %]
 [% IF ( CAN_user_tools_schedule_tasks ) %]
 <li><a href="/cgi-bin/koha/tools/scheduler.pl">مجدول المهام</a></li>
 [% END %]
 [% IF ( CAN_user_tools_edit_quotes ) %]
 <li><a href="/cgi-bin/koha/tools/quotes.pl">محرر الاقتباس</a></li>
 [% END %]
 [% IF ( plugins_enabled && CAN_user_plugins_tool ) %]
 <li><a href="/cgi-bin/koha/plugins/plugins-home.pl?method=tool">برامج الأدوات المساعدة</a></li>
 [% END %]
 [% IF ( CAN_user_tools_upload_general_files ) %]
 <li><a href="/cgi-bin/koha/tools/upload.pl">تحميلات</a></li>
 [% END %]
 [% IF ( CAN_user_tools_access_files ) %]
 <li><a href="/cgi-bin/koha/tools/access_files.pl">الوصول للملفات</a></li>
 [% END %]
 [% IF ( Koha.Preference('OPACReportProblem') && CAN_user_problem_reports ) %]
 <li><a href="/cgi-bin/koha/tools/problem-reports.pl">تقارير مشكلات الأوباك</a></li>
 [% END %]
 </ul>
 [% END # /IF ( CAN_user_tools_edit_calendar... %]
 [% IF ( Koha.Preference('UseCashRegisters') && ( CAN_user_cash_management_cashup || CAN_user_cash_management_anonymous_refund ) ) %]
 <h5>إدارة النقد</h5>
 <ul>
 <li><a href="/cgi-bin/koha/pos/registers.pl">ملخص الدفع النقدي لـ [% Branches.GetLoggedInBranchname | html %]</a></li>
 <li><a href="/cgi-bin/koha/pos/register.pl">سِجل المعاملات لـ [% Registers.session_register_name | html %]</a></li>
 </ul>
 [% END %]
 </div> <!-- /#navmenulist -->
</div> <!-- /#navmenu -->
