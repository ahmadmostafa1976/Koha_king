[% USE Koha %]
<div id="navmenu">
 <div id="navmenulist">
 <h5>التزويد</h5>
 <ul>
 <li><a href="/cgi-bin/koha/acqui/acqui-home.pl">صفحة التزويد الرئيسية</a></li>
 <li><a href="/cgi-bin/koha/acqui/histsearch.pl">بحث متقدم</a></li>
 [% IF ( CAN_user_acquisition_order_receive ) %]<li><a href="/cgi-bin/koha/acqui/lateorders.pl">طلبيات متأخرة</a></li>[% END %]
 [% IF ( CAN_user_suggestions_suggestions_manage ) %]<li><a href="/cgi-bin/koha/suggestion/suggestion.pl">مقترحات</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/invoices.pl">فواتير</a></li>
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/acqui/edifactmsgs.pl">رسائل EDIFACT</a></li>
 [% END %]
 </ul>
 [% IF ( CAN_user_reports || CAN_user_circulate_circulate_remaining_permissions ) %]
 <h5>التقارير</h5>
 <ul>
 [% IF ( CAN_user_reports ) %]
 <li><a href="/cgi-bin/koha/reports/acquisitions_stats.pl">معالج إحصائيات التزويد</a></li>
 <li><a href="/cgi-bin/koha/reports/orders_by_fund.pl">الطلبيات بواسطة التمويل</a></li>
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li><a href="/cgi-bin/koha/circ/reserveratios.pl">معدلات الحجز</a></li>
 [% END %]
 </ul>
 [% END %]
 [% IF ( CAN_user_acquisition_period_manage || CAN_user_acquisition_budget_manage || CAN_user_acquisition_currencies_manage || ( Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage ) || CAN_user_parameters_manage_additional_fields ) %]
 <h5>الإدارة</h5>
 <ul>
 [% IF ( CAN_user_acquisition_period_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">الميزانيات</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_budget_manage ) %]
 <li><a href="/cgi-bin/koha/admin/aqbudgets.pl">التمويلات</a></li>
 [% END %]
 [% IF ( CAN_user_acquisition_currencies_manage ) %]
 <li><a href="/cgi-bin/koha/admin/currency.pl">العملات</a></li>
 [% END %]
 [% IF Koha.Preference('EDIFACT') && CAN_user_acquisition_edi_manage %]
 <li><a href="/cgi-bin/koha/admin/edi_accounts.pl">حسابات EDI</a></li>
 <li><a href="/cgi-bin/koha/admin/edi_ean_accounts.pl">المكتبة EANs</a></li>
 [% END %]
 [% IF CAN_user_acquisition_edit_invoices && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqinvoices">إدارة حقول الفواتير</a>
 </li>
 [% END %]
 [% IF CAN_user_acquisition_order_manage && CAN_user_parameters_manage_additional_fields %]
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqbasket">إدارة حقول سلة الطلبيات</a>
 </li>
 <li>
 <a href="/cgi-bin/koha/admin/additional-fields.pl?tablename=aqorders">إدارة حقول سطور الطلبيات</a>
 </li>
 [% END %]
 </ul>
 [% END %]
 </div>
</div>
