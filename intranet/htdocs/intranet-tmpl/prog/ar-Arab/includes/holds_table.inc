[% USE Koha %]
[% SET hold_cancellation = AuthorisedValues.GetAuthValueDropbox('HOLD_CANCELLATION') %]
[% USE AuthorisedValues %]

[% #This include depends on the asset js/form-submit.js. Any template making use of this include must import form-submit.js as well. %]
[% #FIXME can form-submit.js be imported into this file directly? %]

<table id="patron_holds_table" class="holds_table">
 <thead>
 <tr>
 <th id="checkbox" data-colname="checkbox"><input type="checkbox" class="select_hold_all"/></th>
 <th id="priority" data-colname="priority">الأولوية</th>
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 <th id="change_priority" data-colname="change_priority">تغيير الأولوية</th>
 [% END %]
 <th id="patron" data-colname="patron">المستفيد</th>
 <th id="notes" data-colname="notes">ملاحظات</th>
 <th id="date" data-colname="date">التاريخ</th>
 <th id="expiration" data-colname="expiration">انتهاء</th>
 <th id="pickup_library" data-colname="pickup_library">مكتبة السحب</th>
 <th id="details" data-colname="details">التفاصيل</th>
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 <th id="set_lowest_priority" data-colname="set_lowest_priority"><span style="display:none;">تعيين الأولوية الدنيا</span><i class="fa fa-lg fa-rotate-90 fa-fast-forward" title="بدل الضبط إلى الأولوية الأدنى"></i></th>
 [% END %]
 <th id="delete" data-colname="delete">حذف</th>
 <th id="suspend" data-colname="suspend">تعليق</th>
 <th id="print_slip" data-colname="print_slip">طباعة كعب النقل أو الحجز</th>
 </tr>
 </thead>
 [%- SET first_priority = 0 -%]
 [%- SET found_holds = 0 -%]
 [%- SET last_priority  = holds.last.priority -%]

 [% SET all_priorities = [] %]
 [% FOREACH hold IN holds %]
 [% all_priorities.push( hold.priority ) %]
 [% END %]

 <tbody>
 [% FOREACH hold IN holds %]
 [%- IF !hold.found && first_priority == 0 -%]
 [%- first_priority = hold.priority -%]
 [%- found_holds = loop.index() -%]
 [%- END -%]
 [%- IF Koha.Preference('HoldsSplitQueueNumbering') == 'actual' -%]
 [%- this_priority = hold.priority -%]
 [%- ELSE -%]
 [%- this_priority = loop.count() - found_holds -%]
 [%- END -%]
 [% IF hold.suspend %]
 <tr class="suspend">
 [% ELSE %]
 <tr>
 [% END %]
 <td><input type="checkbox" class="select_hold" data-id="[% hold.reserve_id | html %]"/></td>
 <td>
 <input type="hidden" name="reserve_id" value="[% hold.reserve_id | html %]" />
 <input type="hidden" name="borrowernumber" value="[% hold.borrowernumber | html %]" />
 <input type="hidden" name="biblionumber" value="[% hold.biblionumber | html %]" />
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 [% IF Koha.Preference('HoldsSplitQueue') == "nothing" && !hold.found %]
 <select name="rank-request" class="rank-request" data-hold-id="[% hold.reserve_id | html %]">
 [% IF ( CAN_user_reserveforothers_modify_holds_priority ) %]
 [% FOREACH priority IN all_priorities %]
 [% IF priority == this_priority %]
 <option value="[% priority | html %]" selected="selected">[% priority | html %]</option>
 [% ELSE %]
 <option value="[% priority | html %]">[% priority | html %]</option>
 [% END %]
 [% END %]
 [% ELSE %]
 <option value="[% hold.priority | html %]" selected="selected">[% this_priority | html %]</option>
 [% END %]
 <option value="del">حذف</option>
 </select>
 [% ELSE %]
 <input type="hidden" name="rank-request" class="rank-request" value="[% hold.priority | html %]" data-hold-id="[% hold.reserve_id | html %]">
 <select name="rank-request" class="rank-request" disabled="disabled" data-hold-id="[% hold.reserve_id | html %]">
 [% IF ( hold.found ) %]
 [% IF ( hold.intransit ) %]
 <option value="T" selected="selected">في النقل</option>
 [% ELSIF (hold.inprocessing) %]
 <option value="P" selected="selected">قيد المعالجة</option>
 [% ELSE %]
 <option value="W" selected="selected">في الانتظار</option>
 [% END %]
 [% ELSE %]
 <option value="[% hold.priority | html %]" selected="selected">[% this_priority | html %]</option>
 [% END %]
 </select>
 [% END %]
 [% ELSE %]
 <input type="hidden" name="rank-request" class="rank-request" value="[% hold.priority | html %]" data-hold-id="[% hold.reserve_id | html %]">
 [% hold.priority | html %]
 [% END %]
 </td>
 [%- IF ( CAN_user_reserveforothers_modify_holds_priority ) -%]
 [%- UNLESS hold.found -%]
 [%- SET prev_priority  = loop.prev.priority -%]
 [%- SET next_priority  = loop.next.priority -%]
 <td style="white-space:nowrap;">
 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-next_priority="[% next_priority | html %]" data-op="cud-move" data-prev_priority="[% prev_priority | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-where="up" title="تحريك الحجز لأعلى">
 <i class="fa fa-lg icon-move-hold-up" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-next_priority="[% next_priority | html %]" data-op="cud-move" data-prev_priority="[% prev_priority | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-where="top" title="تحريك الحجز للأعلى">
 <i class="fa fa-lg icon-move-hold-top" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-next_priority="[% next_priority | html %]" data-op="cud-move" data-prev_priority="[% prev_priority | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-where="bottom" title="تحريك الحجز للأسفل">
 <i class="fa fa-lg icon-move-hold-bottom" aria-hidden="true"></i>
 </a>

 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-next_priority="[% next_priority | html %]" data-op="cud-move" data-prev_priority="[% prev_priority | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-where="down" title="تحريك الحجز لأسفل">
 <i class="fa fa-lg icon-move-hold-down" aria-hidden="true"></i>
 </a>
 </td>
 [%- ELSE -%]
 <td></td>
 [%- END -%]
 [%- END -%]
 <td>
 [% INCLUDE 'patron-title.inc' patron=hold.patron hide_patron_infos_if_needed=1 %]
 </td>
 <td>[% hold.notes | html | html_line_break %]</td>
 <td data-order="[% hold.date| html %]">
 [% IF Koha.Preference('AllowHoldDateInFuture') %]
 <input type="text" class="flatpickr" value="[% hold.date | html %]" required="required" size="10" name="reservedate" />
 [% ELSE %]
 [% hold.date | $KohaDates %]
 [% END %]
 </td>
 <td>
 <input type="text" class="flatpickr" data-flatpickr-futuredate="true" value="[% hold.expirationdate | html %]" size="10" name="expirationdate" />
 </td>
 <td>
 [%- IF ( hold.found ) -%]
 <input type="hidden" name="pickup" value="[% hold.wbrcode | html %]" />
 [%- IF ( hold.atdestination ) -%] المادة في الانتظار في <strong> [% hold.wbrname | html %]</strong>[% IF hold.desk_name %], [% hold.desk_name | html %],[% END %] منذ [% hold.waiting_date | $KohaDates %] [%- ELSIF (hold.intransit) -%] يتم نقل المادة إلى <strong> [% hold.wbrname | html %]</strong>
 [%- ELSIF (hold.inprocessing) -%] جاري معالجة المادة في <strong> [% hold.wbrname | html %]</strong>
 [%- ELSE -%] الحجز متوقع في <strong>[% hold.wbrname | html %]</strong>، يرجى الرد لتأكيد الحالة [%- END -%] [%- ELSE -%] [%- IF Koha.Preference('IndependentBranches') && Branches.all().size == 1 -%] [% Branches.GetName(hold.branchcode) | html %] <input type="hidden" name="pickup" value="[% hold.branchcode | html %]" />
 [%- ELSE -%]
 <select class="pickup_location_dropdown"
                                    data-selected="[% hold.branchcode | html %]"
                                    data-hold-id="[% hold.reserve_id | html %]"
                                    data-pickup-location-source="hold"
                                    name="pickup">
 <option selected="selected" value="[% hold.branchcode | html %]">[% Branches.GetName(hold.branchcode) | html %]</option>
 <option value="" disabled="disabled" class="loading">جاري التحميل...</option>
 </select>
 <img class="loading_[% hold.reserve_id | html %]" src="[% interface | html %]/[% theme | html %]/img/spinner-small.gif" alt="" style="display:none;"/>
 [%- END -%]
 [%- END -%]
 </td>
 <td>
 [%- IF ( hold.found ) -%]
 <a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% hold.biblionumber | uri %]&amp;itemnumber=[% hold.itemnumber | uri %]#item[% hold.itemnumber | uri %]">
 [%- IF ( hold.barcodenumber ) -%]
 [%- hold.barcodenumber | html -%]
 [%- ELSE -%]
 <span>لا يوجد باركود</span>
 [%- END -%]
 <input type="hidden" name="itemnumber" value="[% hold.itemnumber | html %]" />
 </a>
 [%- ELSE -%]
 [%- IF ( hold.item_level_hold ) -%]
 <em>
 [%- IF ! hold.change_hold_type_allowed -%]
 <span>المادة فقط</span>
 <a href="/cgi-bin/koha/catalogue/moredetail.pl?biblionumber=[% hold.biblionumber | uri %]&amp;itemnumber=[% hold.itemnumber | uri %]#item[% hold.itemnumber | uri %]">
 [%- IF ( hold.barcodenumber ) -%]
 [%- hold.barcodenumber | html -%]
 [%- ELSE -%]
 <span>لا يوجد باركود</span>
 [%- END -%]
 <input type="hidden" name="itemnumber" value="[% hold.itemnumber | html %]" />
 </a>
 [%- ELSE -%]
 <select name="change_hold_type_[% hold.reserve_id | html %]">
 <option selected="selected" value="">مادة وحيدة [%- IF ( hold.barcodenumber ) -%] [%- hold.barcodenumber | html -%] [%- ELSE -%] لا يوجد باركود [%- END -%] </option>
 <option value="1">المتاح التالى</option>
 </select>
 [%- IF ( hold.barcodenumber ) -%]
 <input type="hidden" name="itemnumber" value="[% hold.itemnumber | html %]" />
 [%- END -%]
 [%- IF hold.itemtype -%]
 <span style="display:none">المتاح التالي [% ItemTypes.GetDescription( hold.itemtype ) | html %] المادة</span>
 [%- ELSE -%]
 <span style="display:none">المتاح التالى</span>
 [%- END -%]
 [%- END -%]
 </em>
 [%- ELSE -%]
 [%- IF hold.itemtype -%]
 <em>المتاح التالي [% ItemTypes.GetDescription( hold.itemtype ) | html %] المادة</em>
 [%- ELSIF hold.object.item_group -%]
 <em>المادة المتاحة التالية من المجموعة <strong>[% hold.object.item_group.description | html %]</strong></em>
 [%- ELSE -%]
 <em>المتاح التالى</em>
 [%- END -%]

 <input type="hidden" name="itemnumber" value="" />
 [%- END -%]
 [%- END -%]
 [%- IF hold.non_priority -%]
 <br><i>حجز بلا أولوية</i>
 [%- END -%]
 </td>
 [%- IF ( CAN_user_reserveforothers_modify_holds_priority ) -%]
 [%- UNLESS hold.found -%]
 <td>
 [% IF ( hold.lowestPriority ) %]
 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-op="cud-setLowestPriority" data-reserve_id="[% hold.reserve_id | html %]" title="إزالة الأولوية الأدنى">
 <i class="fa fa-lg fa-rotate-90 icon-unset-lowest" aria-hidden="true"></i>
 [% ELSE %]
 <a class="hold-arrow" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-date="[% hold.date | html %]" data-op="cud-setLowestPriority" data-reserve_id="[% hold.reserve_id | html %]" title="تعيين الأولوية الدنيا">
 <i class="fa fa-lg fa-rotate-90 icon-set-lowest" aria-hidden="true"></i>
 [% END %]
 </a>
 </td>
 [%- ELSE -%]
 <td></td>
 [%- END -%]
 [%- END -%]
 <td>
 <a class="cancel-hold" data-biblionumber="[% hold.biblionumber | html %]" data-borrowernumber="[% hold.borrowernumber | html %]" data-id="[% hold.reserve_id | html %]" href="request.pl?op=cancel&borrowernumber=[% hold.borrowernumber | html %]&biblionumber=[% hold.biblionumber | html %]&reserve_id=[% hold.reserve_id | html %]&date=[% hold.date | html %]" title="إلغاء العقد">
 <i aria-label="إلغاء العقد" class="fa fa-trash"></i>
 </a>
 </td>
 <td>
 [% IF Koha.Preference('SuspendHoldsIntranet') %]
 [% UNLESS ( hold.found ) %]
 <button class="btn btn-default btn-xs toggle-suspend" data-reserve-id="[% hold.reserve_id | html %]" data-biblionumber="[% hold.biblionumber | html %]">
 [% IF ( hold.suspend ) %]
 <i class="fa fa-play" aria-hidden="true"></i> إلغاء تعليق [% ELSE %] <i class="fa fa-pause" aria-hidden="true"></i> تعليق [% END %] </button>

 [% IF Koha.Preference('AutoResumeSuspendedHolds') %]
 <label for="suspend_until_[% hold.reserve_id | html %]">[% IF ( hold.suspend ) %] في [% ELSE %] حتى [% END %]</label>
 <input type="text" name="suspend_until_[% hold.reserve_id | html %]" id="suspend_until_[% hold.reserve_id | html %]" size="10" value="[% hold.suspend_until | html %]" class="flatpickr" data-flatpickr-futuredate="true" />
 [%- ELSE -%]
 <input type="hidden" name="suspend_until_[% hold.reserve_id | html %]" id="suspend_until_[% hold.reserve_id | html %]" value=""/>
 [%- END -%]
 [%- END -%]
 [%- END # IF SuspendHoldsIntranet -%]
 [%- IF ( hold.found ) -%]
 <a class="btn btn-default  submit-form-link" href="#" id="revert_hold_[% hold.reserve_id | html %]" data-op="cud-move" data-where="down" data-first_priority="[% first_priority | html %]" data-last_priority="[% last_priority | html %]" data-prev_priority="0" data-next_priority="1" data-borrowernumber="[% hold.borrowernumber | html %]" data-biblionumber="[% hold.biblionumber | html %]" data-itemnumber="[% hold.itemnumber | html %]" data-reserve_id="[% hold.reserve_id | html %]" data-date="[% hold.date | html %]" data-action="request.pl" data-method="post">[% IF hold.intransit %]عكس حالة النقل[% ELSE %]عكس حالة في الانتظار[% END %]</a>
 [%- END -%]
 </td>
 [% IF ( hold.intransit || hold.atdestination ) %]
 <td><input class="printholdslip" data-reserve_id="[% hold.reserve_id | html %]" name="printholdslip" type="button" value="طباعة الكعب"></td>
 [% ELSE %]
 <td></td>
 [% END %]
 </tr>
 [% END %]
 </tbody>
</table>
