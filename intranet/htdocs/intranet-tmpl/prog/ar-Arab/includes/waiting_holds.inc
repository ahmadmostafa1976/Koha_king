[% USE KohaDates %]
[% USE ItemTypes %]
[% USE AuthorisedValues %]
<table class="holds_table" id="[% table_name | html %]">
 <thead>
 <tr>
 <th class="NoSort"><input type="checkbox" class="select_hold_all"/></th>
 <th>في الانتظار منذ</th>
 <th>تاريخ وضع الحجز</th>
 [% IF table_name == 'holdscr' %]
 <th>تاريخ طلب الإلغاء</th>
 [% END %]
 <th>تاريخ الإنتهاء</th>
 <th class="anti-the">عنوان</th>
 <th>المستفيد</th>
 <th>المكتبة الرئيسية</th>
 <th>المكتبة الحالية</th>
 <th>موقع الرف</th>
 <th>رقم الاستدعاء</th>
 <th>رقم النسخة</th>
 <th>الترقيم</th>
 <th class="NoSort noExport">الإجراءات</th>
 </tr>
 </thead>
 <tbody>
 [% FOREACH reserveloo IN reserveloop %]
 <tr>
 <th><input type="checkbox" class="select_hold" data-id="[% reserveloo.reserve_id | html %]"/></th>
 <td data-order="[% reserveloo.waitingdate | html %]"><span>[% reserveloo.waitingdate | $KohaDates %]</span></td>
 <td data-order="[% reserveloo.reservedate | html %]"><span>[% reserveloo.reservedate | $KohaDates %]</span></td>
 [% IF table_name == 'holdscr' %]
 [% IF reserveloo.cancellation_requests.count %]
 [% FOREACH cancellation_request IN reserveloo.cancellation_requests %]
 [% IF loop.first %]
 <td data-order="[% cancellation_request.creation_date | html %]">
 [% END %]
 <span>[% cancellation_request.creation_date | $KohaDates %]</span>
 [% IF loop.last %]
 </td>
 [% END %]
 [% END %]
 [% ELSE %]
 <td></td>
 [% END %]
 [% END %]
 <td data-order="[% reserveloo.expirationdate | html %]"><span>[% reserveloo.expirationdate | $KohaDates %]</span></td>
 <td>
 [% INCLUDE 'biblio-title.inc' biblio=reserveloo.biblio link = 1 %]
 [% UNLESS ( item_level_itypes ) %]
 [% IF ( ItemTypes.GetDescription(reserveloo.item.effective_itemtype) ) %]&nbsp; (<strong>[% ItemTypes.GetDescription(reserveloo.item.effective_itemtype) | html %]</strong>)
 [% END %]
 [% END %]
 <br />الباركود : [% reserveloo.item.barcode | html %] </td>
 <td><a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% reserveloo.borrower.borrowernumber | uri %]">[% INCLUDE 'patron-title.inc' patron=reserveloo.borrower invert_name=1 no_title=1 %]</a>
 [% IF ( reserveloo.borrower.phone ) %]<br /><span class="patron_phone">[% reserveloo.borrower.phone | html %]</span>[% END %]
 [% IF ( reserveloo.borrower.notice_email_address ) %]
 <span class="patron_email"><br /><a href="mailto:[% reserveloo.borrower.notice_email_address | uri %]?subject=[% "Hold waiting: " | uri %][% reserveloo.biblio.title | uri %]">
 [% reserveloo.borrower.notice_email_address | html %]</a></span>
 [% END %]
 </td>
 <td>[% Branches.GetName( reserveloo.item.homebranch ) | html %]</td>
 <td>[% Branches.GetName( reserveloo.item.holdingbranch ) | html %][% IF (reserveloo.desk_id  ) %], [% reserveloo.desk.desk_name | html %][% END %]</td>
 <td>[% AuthorisedValues.GetDescriptionByKohaField( kohafield => 'items.location', authorised_value => reserveloo.item.location) | html %]</td>
 <td>[% reserveloo.item.itemcallnumber | html %]</td>
 <td>[% reserveloo.item.copynumber | html %]</td>
 <td>[% reserveloo.item.enumchron | html %]</td>
 <td>
 <form name="cancelReserve" action="waitingreserves.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-cancel">
 <input type="hidden" name="borrowernumber" value="[% reserveloo.borrower.borrowernumber | html %]" />
 <input type="hidden" name="itemnumber" value="[% reserveloo.item.itemnumber | html %]" />
 <input type="hidden" name="fbr" value="[% reserveloo.item.holdingbranch | html %]" />
 <input type="hidden" name="tbr" value="[% reserveloo.item.homebranch | html %]" />
 <input type="hidden" name="tab" value="[% tab | html %]">
 [% IF ( reserveloo.item.homebranch != reserveloo.item.holdingbranch ) %]
 <button type="submit" class="btn btn-default btn-xs"><i class="fa fa-times"></i> إلغاء الحجز والعودة إلى: [% Branches.GetName( reserveloo.item.homebranch ) | html %]</button>
 [% ELSE %]
 <button type="submit" class="btn btn-default btn-xs"><i class="fa fa-times"></i> إلغاء العقد</button>
 [% END %]
 </form>
 </td>
 </tr>
 [% END %]
 </tbody>
</table>
