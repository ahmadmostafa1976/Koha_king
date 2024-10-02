[% USE raw %]
[% USE Branches %]
[% USE Categories %]
[% SET ClaimReturnedWarningThreshold = Koha.Preference('ClaimReturnedWarningThreshold') %]
[% SET return_claims = patron.return_claims %]
[% SET logged_in_branchcode = Branches.GetLoggedInBranchcode() %]

[% IF ( has_modifications || warndeparture || returnbeforeexpiry || expired || patron.gonenoaddress || patron.lost || userdebarred || odues || ( return_claims.count > ClaimReturnedWarningThreshold ) || age_limitations || limited_category || charges || charges_guarantors_guarantees || charges_guarantees || credits ) %]
 <h3>انتباه</h3>
 <ul>
 [% IF ( has_modifications ) %]
 <li class="has_modifications">
 <span class="circ-hlt">تعديلات في الانتظار:</span>
 [% IF CAN_user_borrowers_edit_borrowers && ( !Koha.Preference('IndependentBranchesPatronModifications') || borrower.branch == branch ) %]
 <a href="/cgi-bin/koha/members/members-update.pl?active=[% patron.borrowernumber | uri %]">معاينة التعديلات في الانتظار</a>
 [% ELSE %]
 <span>المستفيد لديه تعديلات في الانتظار</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( warndeparture ) %]
 <li class="warndeparture">
 <span class="circ-hlt">انتهاء:</span>
 <span>ستنتهي بطاقة المستفيد في [% patron.dateexpiry | $KohaDates %].</span>
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=circ&amp;reregistration=y">تجديد</a> أو <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | html %]">تحرير التفاصيل</a>
 </li>
 [% END %]

 [% IF ( returnbeforeexpiry ) %]
 <li class="returnbeforeexpiry">
 <span class="circ-hlt">ضبط تاريخ الاستحقاق للانتهاء:</span> تم تفعيل تفضيل النظام  ReturnBeforeExpiry لديك مما يعني أن تاريخ الانتهاء قبل تاريخ الاستحقاق، سيتم ضبط تاريخ الاستحقاق إلى تاريخ الانتهاء </li>
 [% END %]

 [% IF ( expired ) %]
 <li class="expired">
 <span class="circ-hlt">انتهاء:</span>
 <span>لقد انتهت بطاقة المستفيد.</span>
 [% IF ( expiry ) %]
 <span>لقد انتهت بطاقة المستفيد في [% expiry | $KohaDates %]</span>
 [% END %]
 <a href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | uri %]&amp;destination=circ&amp;reregistration=y">تجديد</a> أو <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | html %]">تحرير التفاصيل</a>
 </li>
 [% END %]

 [% IF ( patron.gonenoaddress ) %]
 <li class="gonenoaddress blocker">
 <span title="يتم تعيين علامة gonoaddress في تسجيلة المستفيد"><span class="circ-hlt">عنوان:</span> تم وضع علامة على عنوان المستفيد بأنه موضع شك</span> <a class="btn btn-default btn-xs" href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3#memberentry_account_flags"><i class="fa-solid fa-pencil" aria-hidden="true"></i> تحرير</a>
 </li>
 [% END %]

 [% IF ( patron.lost ) %]
 <li class="lost blocker">
 <span title="تم وضع علامة على بطاقة المستفيد على أنها ضائعة"><span class="circ-hlt">ضائعة: </span> تم وضع علامة على بطاقة المستفيد على أنها ضائعة</span> <a class="btn btn-default btn-xs" href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3#memberentry_account_flags"><i class="fa-solid fa-pencil" aria-hidden="true"></i> تحرير</a>
 </li>
 [% END %]

 [% IF ( userdebarred ) %]
 <li class="userdebarred blocker">
 <span class="circ-hlt"> مقيدة منذ [% debarredsince | $KohaDates %]:</span> حساب المستفيد مقيد[% IF ( userdebarreddate ) %] حتى [% userdebarreddate | $KohaDates %] [% END %] [% IF ( debarredcomment ) %] بالتفسير: <br/>
 <em>
 [% IF debarredcomment.search('OVERDUES_PROCESS') %]
 Restriction added by overdues process [% debarredcomment.remove('OVERDUES_PROCESS ') | $raw | html_line_break %]
 [% ELSE %]
 [% FOREACH restriction IN patron.restrictions %]
 <div class="[% restriction.type.code | lower | html %]_restriction">
 <span class="restriction_expiration">
 [% IF restriction.expiration %]
 [% restriction.expiration | $KohaDates %]
 [% ELSE %]
 <strong>غير معرّف</strong>
 [% END %]
 </span>
 <span class="restriction_detail">
 [%- restriction.type.display_text | html -%][%- IF restriction.comment -%]: [%- restriction.comment | html_line_break -%][%- END -%]
 </span>
 </div>
 [% END %]
 [% END %]
 </em><br/>
 [% END %]
 <a class="btn btn-xs btn-default" href="#reldebarments-tab" onclick="$('#reldebarments-tab').click()"><i class="fa fa-ban"></i> عرض القيود</a>
 </li> <!-- /.blocker -->
 [% END # /IF userdebarred %]

 [% IF ( odues ) %]
 <li class="odues blocker">
 <span class="circ-hlt">المتأخرات:</span> المستفيد لديه ITEMS OVERDUE <a href="#checkouts">انظر المواد المظللة أدناه</a>
 </li>
 [% END %]

 [% IF return_claims.count > ClaimReturnedWarningThreshold %]
 <li class="return_claims blocker">
 <span class="circ-hlt return-claims">إدعاء إعادة:</span> المستفيد لديه [% return_claims.count | html %] RETURN CLAIMS </li>
 [% END %]

 [% IF age_limitations %]
 <li class="invalid_age">
 <span class="circ-hlt">عمر المستفيد غير صحيح لفئته.</span>
 الأعمار المسموح لها هي [% age_low | html %]-[% age_high | html %]. <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3" class="btn btn-default btn-xs">تغيير الفئة</a>
 </li>
 [% END %]

 [% IF limited_category %]
 <li class="limited_category">
 <span class="circ-hlt">The patron's current category ([% Categories.GetName(patron.categorycode) | html %]) is limited to other libraries.</span>
 <a href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;borrowernumber=[% patron.borrowernumber | uri %]&amp;step=3" class="btn btn-default btn-xs">تغيير الفئة</a>
 </li>
 [% END %]

 [% IF ( charges ) %]
 [% INCLUDE 'blocked-fines.inc' fines = chargesamount %]
 [% END %]

 [% IF ( charges_guarantors_guarantees ) %]
 <li class="charges_guarantors_guarantees">
 <span class="circ-hlt">الرسوم:</span> يدين كفيلي المستفيد ومكفوليهم بشكل إجمالي [% charges_guarantors_guarantees | $Price %]. [% IF noissues %] <span class="circ-hlt">تم حظر الإعارات لأن رصيد الغرامة قد تجاوز الحد المسموح به.</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( charges_guarantees ) %]
 <li class="charges_guarantees">
 <span class="circ-hlt">الرسوم:</span> يدين ضامني المستفيد بشكل إجمالي بـ  [% chargesamount_guarantees | $Price %].[% IF noissues %] <span class="circ-hlt">تم حظر الإعارات لأن رصيد الغرامة قد تجاوز الحد المسموح به.</span>
 [% END %]
 </li>
 [% END %]

 [% IF ( credits ) %]
 <li class="credits">
 <span class="circ-hlt">الاعتمادات المالية:</span> المستفيد المالي لديه ائتمان مالي [% IF ( creditsamount ) %] من <span class="credit"><strong>[% creditsamount | $Price %]</strong></span>[% END %]
 </li>
 [% END %]
 [% IF (noissues && CAN_user_circulate_force_checkout && !moremember) %]
 <li>
 <span class="override_debarment">
 <a href="/cgi-bin/koha/circ/circulation.pl?forceallow=1&amp;borrowernumber=[% patron.borrowernumber | uri %]" class="btn btn-xs btn-default">تخطي القيد مؤقتاً</a>
 </span>
 </li>
 [% END %]
 </ul>

[% END # /F ( has_modifications || warndeparture... %]

[% IF waiting_recalls.count %]
 <div id="recallswaiting" class="circmessage">
 [% SET waiting_here = 0 %]
 [% SET waiting_elsewhere = 0 %]
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id == logged_in_branchcode  ) %]
 [% waiting_here = waiting_here + 1 %]
 [% ELSE %]
 [% waiting_elsewhere = waiting_elsewhere + 1 %]
 [% END %]
 [% END %]

 [% IF ( waiting_here > 0 ) %]
 <h4>استدعاءات في الانتظار هنا ([% waiting_here | html %])</h4>
 <ul>
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id == logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% w.biblio_id | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] بواسطة [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>تم وضع استدعاء على [% w.created_date | $KohaDates %].</span>
 <br />
 <strong class="waitinghere">
 [% SET expires_on = w.expiration_date %] في الانتظار هنا [% IF expires_on %] حتى [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]

 [% IF ( waiting_elsewhere > 0 ) %]
 <h4>استدعاءات في الانتظار في مكتبات أخرى ([% waiting_elsewhere | html %])</h4>
 <ul>
 [% FOREACH w IN waiting_recalls %]
 [% IF ( w.pickup_library_id != logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/recalls/request.pl?biblionumber=[% w.biblio_id | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] بواسطة [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>تم وضع استدعاء على [% w.created_date | $KohaDates %].</span>
 <br />
 <strong>
 [% SET expires_on = w.expiration_date %] في الانتظار في[% Branches.GetName( w.pickup_library_id ) | html %] [% IF expires_on %] حتي [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 </div>
[% END # /IF waiting_recalls.count %]

[% IF WaitingHolds.count %]
 <div id="holdswaiting" class="circmessage">
 [% SET waiting_here = 0 %]
 [% SET waiting_elsewhere = 0 %]
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode == logged_in_branchcode  ) %]
 [% waiting_here = waiting_here + 1 %]
 [% ELSE %]
 [% waiting_elsewhere = waiting_elsewhere + 1 %]
 [% END %]
 [% END %]

 [% IF ( waiting_here > 0 ) %]
 <h4>حجوزات في الانتظار هنا ([% waiting_here | html %])</h4>
 <ul>
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode == logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% w.biblio.biblionumber | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] بواسطة [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span class="holddate">تم وضع حجز على [% w.reservedate | $KohaDates %].</span>
 <br />
 <strong class="waitinghere">
 [% SET expires_on = w.expirationdate %] في الانتظار هنا [% IF expires_on %] حتى [% expires_on | $KohaDates %] [% END %]. </strong>
 <strong class="waitingsince">
 في الانتظار هنا منذ [% w.waitingdate | $KohaDates %]. </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]

 [% IF ( waiting_elsewhere > 0 ) %]
 <h4>حجوزات في الانتظار في مكتبات أخرى ([% waiting_elsewhere | html %])</h4>
 <ul>
 [% FOREACH w IN WaitingHolds %]
 [% IF ( w.branch.branchcode != logged_in_branchcode  ) %]
 <li>
 <a href="/cgi-bin/koha/reserve/request.pl?biblionumber=[% w.biblio.biblionumber | uri %]">[% w.biblio.title | html %]</a>
 ([% ItemTypes.GetDescription( w.item.effective_itemtype ) | html %]), [% IF ( w.biblio.author ) %] بواسطة [% w.biblio.author | html %] [% END %] [% IF ( w.item.itemcallnumber ) %] [[% w.item.itemcallnumber | html %]] [% END %] <span>تم وضع حجز على [% w.reservedate | $KohaDates %].</span>
 <br />
 <strong>
 [% SET expires_on = w.expirationdate %] في الانتظار في[% w.branch.branchname | html %] [% IF expires_on %] حتي [% expires_on | $KohaDates %] [% END %] </strong>
 </li>
 [% END %]
 [% END %]
 </ul>
 [% END %]
 </div>
[% END # /IF WaitingHolds.count %]

[% IF Koha.Preference("CurbsidePickup") %]
 [% SET curbside_pickups = patron.curbside_pickups.search( branchcode => Branches.GetLoggedInBranchcode ) %]
 [% IF curbside_pickups.count %]
 <div id="curbside_pickups" class="circmessage">
 <h4>الالتقاطات الجانبية المجدولة هنا</h4>
 <ul>
 [% FOR cp IN curbside_pickups %]
 <li>في [% cp.scheduled_pickup_datetime | $KohaDates %]: [% SWITCH cp.status %] [% CASE 'to-be-staged' %] <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=to-be-staged">
 ليتم تجهيزها</a>
 [% CASE 'staged-and-ready' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=staged-and-ready">
 مجهزة وجاهزة</a>
 [% CASE 'patron-is-outside' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=patron-is-outside">
 المستفيد في الخارج!</a>
 [% CASE 'delivered' %]
 <a href="/cgi-bin/koha/circ/curbside_pickups.pl?tab=delivered-today">
 تم التوصيل</a>
 [% CASE %]<span>حالة غير معروفة "[% cp.status | html %]"</span>
 [% END %]
 </li>
 [% END %]
 </ul>
 </div>
 [% END %]
[% END %]

[% IF ( patron.borrowernotes ) %]
 <div id="circnotes" class="circmessage">
 <h4>ملاحظات</h4>
 <ul>
 <li>
 <span class="circ-hlt">
 [% patron.borrowernotes | $raw | html_line_break %]
 </span>
 </li>
 </ul>
 </div> <!-- /#circnotes -->
[% END # /IF patron.borrowernotes %]

[% IF ( patron_messages ) %]
 <div id="messages" class="circmessage">
 <h4>رسائل</h4>
 <ul>
 [% FOREACH patron_message IN patron_messages %]
 <li>
 [% IF(patron_message.message_type == "L") %]
 <span class="circ-hlt">
 [% ELSE %]
 <span>
 [% END %]
 [% patron_message.message_date | $KohaDates %]
 [% Branches.GetName( patron_message.branchcode ) | html %]
 [% IF patron_message.manager_id %]
 ( <a href="/cgi-bin/koha/members/moremember.pl?borrowernumber=[% patron_message.manager_id | uri %]">[% patron_message.get_column('manager_firstname') | html %] [% patron_message.get_column('manager_surname') | html %]</a> )
 [% END %]
 <em>"[% patron_message.message | html | html_line_break %]"</em>
 [% IF patron_message.patron_read_date %] قراءة: <em>[% patron_message.patron_read_date | $KohaDates %]</em>
 [% END %]
 </span>
 [% IF patron_message.branchcode == Branches.GetLoggedInBranchcode OR Koha.Preference('AllowAllMessageDeletion') %]
 [% IF moremember %]
 <a id="#edit_message_form_[% patron_message.message_id | html %]" class="btn btn-link edit_message" href="#edit_message_form_[% patron_message.message_id | uri %]" data-target="#edit_message_form_[% patron_message.message_id | html %]" data-toggle="modal" class="btn btn-default"><i class="fa-solid fa-pencil" aria-hidden="true"></i> تحرير</a>
 <form action="/cgi-bin/koha/circ/del_message.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete">
 <input type="hidden" name="message_id" value="[% patron_message.message_id | html %]">
 <input type="hidden" name="borrowernumber" value="[% patron_message.borrowernumber | html %]">
 <input type="hidden" name="from" value="moremember">
 <button type="submit" class="btn btn-link delete_message"><i class="fa fa-trash-can"></i> حذف</button>
 </form>
 [% ELSE %]
 <a id="#edit_message_form_[% patron_message.message_id | html %]" class="btn btn-link edit_message" href="#edit_message_form_[% patron_message.message_id | uri %]" data-target="#edit_message_form_[% patron_message.message_id | html %]" data-toggle="modal" class="btn btn-default"><i class="fa-solid fa-pencil" aria-hidden="true"></i> تحرير</a>
 <form action="/cgi-bin/koha/circ/del_message.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-delete">
 <input type="hidden" name="message_id" value="[% patron_message.message_id | html %]">
 <input type="hidden" name="borrowernumber" value="[% patron_message.borrowernumber | html %]">
 <button type="submit" class="btn btn-link delete_message"><i class="fa fa-trash-can"></i> حذف</button>
 </form>
 [% END %]
 [% END %]
 </li>
 [% END %]
 </ul>
 <a id="addnewmessageLabel" href="#add_message_form" class="btn btn-link" data-toggle="modal"><i class="fa fa-plus"></i> إضافة رسالة جديدة</a>
 </div> <!-- /#messages -->

 [% FOREACH pm IN patron_messages %]
 <div id="edit_message_form_[% pm.message_id | html %]" class="modal" tabindex="-1" role="dialog" aria-labelledby="#edit_message_form_[% patron_message.message_id | html %]" aria-hidden="true">
 <div class="modal-dialog">
 <div class="modal-content">
 <form method="post" action="/cgi-bin/koha/circ/add_message.pl" id="message_form" name="message_f">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-edit_message">
 <input type="hidden" name="message_id" value="[% pm.message_id | html %]"/>
 <div class="modal-header">
 <h3>تحرير الرسالة</h3>
 </div>
 <div class="modal-body">
 <div class="form-group">
 <label for="message_type">الرسالة مخصصة لـ:</label>
 <select name="message_type" id="message_type" disabled>
 [% IF pm.message_type == "L" %]
 <option value="L" selected="selected">ملاحظة الموظفين الداخلية</option>
 [% ELSE %]
 <option value="L">ملاحظة الموظفين الداخلية</option>
 [% END %]

 [% IF pm.message_type == "B" %]
 <option value="B" selected="selected">أوباك- [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% ELSE %]
 <option value="B">أوباك- [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% END %]
 </select>
 </div>
 <div class="form-group">
 <textarea rows="3" class="modal-textarea" name="borrower_message" id="borrower_message" >[% pm.message | html %]</textarea>
 </div>
 </div>
 <div class="modal-footer">
 <button class="btn btn-default approve" type="submit"><i class="fa fa-check"></i> حفظ</button>
 <button class="btn btn-default deny cancel" href="#" data-dismiss="modal" aria-hidden="true"><i class="fa fa-times"></i> إلغاء</button>
 </div>
 </form>
 </div>
 </div>
 </div>
 [% END %]

[% END # /IF patron_messages %]
