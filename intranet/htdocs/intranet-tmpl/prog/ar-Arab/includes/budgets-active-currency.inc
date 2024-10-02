[% IF ( currency ) %]
 [% IF ( not hide ) %]
 <p><strong>العملة = [% currency | html %]</strong></p>
 [% END %]
[% ELSE %]
 <div class="dialog alert">
 <h3>لم يتم تعريف أي عملة نشطة</h3>
 [% IF CAN_user_acquisition_currencies_manage %]
 <p><a href="/cgi-bin/koha/admin/currency.pl">يرجى تحديد عملة نشطة.</a></p>
 [% ELSE %]
 <p>يجب على مسؤول النظام تحديد عملة نشطة.</p>
 [% END %]
 </div>
[% END %]
