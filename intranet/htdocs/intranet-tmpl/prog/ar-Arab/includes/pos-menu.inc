[% USE Branches %]
[% USE Registers %]
<div id="navmenu">
 <div id="navmenulist">
 [% IF ( CAN_user_cash_management_cashup || CAN_user_cash_management_anonymous_refund ) %]
 <h5>إدارة النقد</h5>
 <ul>
 <li><a href="/cgi-bin/koha/pos/pay.pl">نقطة البيع</a></li>
 [% IF !(Registers.session_register_name == '') %]
 <li><a href="/cgi-bin/koha/pos/register.pl">سِجل المعاملات لـ [% Registers.session_register_name | html %]</a></li>
 [% END %]
 <li><a href="/cgi-bin/koha/pos/registers.pl">ملخص الدفع النقدي لـ [% Branches.GetLoggedInBranchname | html %]</a></li>
 </ul>
 [% END %]
 [% IF ( CAN_user_parameters_manage_cash_registers || CAN_user_parameters_manage_accounts) %]
 <h5>الإدارة</h5>
 <ul>
 [% IF ( CAN_user_parameters_manage_cash_registers ) %]
 <li><a href="/cgi-bin/koha/admin/cash_registers.pl">تهيئة السجلات النقدية</a></li>
 [% END %]

 [% IF ( CAN_user_parameters_manage_accounts ) %]
 <li><a href="/cgi-bin/koha/admin/debit_types.pl">تهيئة مواد للشراء</a></li>
 [% END %]
 </ul>
 [% END %]
 </div>
</div>
