[% USE Price %]
[% SET NoIssuesCharge = Koha.Preference('noissuescharge') %]
[% IF fines and fines > 0 %]
 <li>
 <span class="circ-hlt">الرسوم:</span>
 <span>لدى المستفيد رسوم غير مسددة بمبلغ [% fines | $Price %].</span>
 [% IF !Koha.Preference('AllowFineOverride') && NoIssuesCharge && fines > NoIssuesCharge %]
 <span class="circ-hlt">تم حظر الإعارات لأن رصيد الغرامة قد تجاوز الحد المسموح به.</span>
 [% END %]
 [% IF CAN_user_updatecharges_remaining_permissions %]
 <a href="/cgi-bin/koha/members/pay.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-default btn-xs" >تسديد</a>
 <a href="/cgi-bin/koha/members/paycollect.pl?borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-default btn-xs" >دفع كل الرسوم</a>
 [% END %]
 </li>
[% END %]
