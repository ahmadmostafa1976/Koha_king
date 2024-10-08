[% USE Koha %]
[% USE Branches %]
[% USE Categories %]
[% USE Notices %]
[% USE AuthorisedValues %]
[% USE NoticeTemplates %]
[% USE scalar %]
<div id="toolbar" class="btn-toolbar">
 [% IF CAN_user_borrowers_edit_borrowers %]
 <a id="editpatron" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=edit_form&amp;destination=circ&amp;borrowernumber=[% patron.borrowernumber | html %]"><i class="fa-solid fa-pencil" aria-hidden="true"></i> تحرير</a>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 [% IF patron.is_adult AND Koha.Preference("borrowerRelationship") %]
 <a id="addchild" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=add_form&amp;guarantor_id=[% patron.borrowernumber | html %]"><i class="fa fa-plus"></i> إضافة ضمان</a>
 [% END %]
 <a id="changepassword" class="btn btn-default" href="/cgi-bin/koha/members/member-password.pl?member=[% patron.borrowernumber | html %]"><i class="fa fa-lock"></i> تغيير كلمة المرور</a>
 <a id="duplicate" class="btn btn-default" href="/cgi-bin/koha/members/memberentry.pl?op=duplicate&amp;borrowernumber=[% patron.borrowernumber | html %]"><i class="fa fa-copy"></i> نسخ</a>
 [% END %]

 [% IF CAN_user_circulate_circulate_remaining_permissions %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-print"></i> طباعة <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a class="printslip" data-code="printsummary" href="#">طباعة الملخص</a></li>
 <li><a class="printslip" data-code="issueslip" href="#">طباعة الكعب</a></li>
 <li><a class="printslip" data-code="issueqslip" href="#">طباعة كعب سريعة</a></li>
 [% IF patron.account_balance != 0 %]
 <li><a id="printfineslip" target="_blank" href="/cgi-bin/koha/members/printnotice.pl?notice=ACCOUNTS_SUMMARY&borrowernumber=[% patron.borrowernumber | uri %]">طباعة رصيد الحساب</a></li>
 [% END %]
 [% IF patron.has_overdues %]
 <li><a id="print_overdues" href="#">طباعة المتأخرات</a></li>
 [% END %]
 [% IF patron.privacy < 2 %] [%# 2 is the privacy rule "Never" (Delete my history immediately) %]
 <li><a class="printslip" data-code="checkinslip" href="#">طباعة كعب الرد</a></li>
 [% END %]
 [% FOREACH notice IN Notices.GetTemplates( 'patron_slip' ) %]
 <li><a class="printslip" data-code="[% notice.code | html %]" href="#">طباعة  [% notice.name | html %]</a></li>
 [% END %]
 </ul>
 </div>
 [% END %]

 [% IF ( CAN_user_reserveforothers ) %]
 <a id="searchtohold" class="btn btn-default" href="#"><i class="fa fa-search"></i> بحث المقتنيات</a>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <a id="addnewmessageLabel" href="#add_message_form" data-toggle="modal" class="btn btn-default"><i class="fa-solid fa-comment"></i> إضافة رسالة</a>
 [% END %]

 [% IF Koha.Preference('CurbsidePickup') %]
 <a id="curbsidePickupLabel" href="/cgi-bin/koha/circ/curbside_pickups.pl?op=find-patron&borrowernumber=[% patron.borrowernumber | html %]" class="btn btn-default"><i class="fa-solid fa-rotate"></i> جدولة التقاط</a>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown">المزيد <span class="caret"></span></button>
 <ul class="dropdown-menu dropdown-menu-right">
 [% IF CAN_user_borrowers_edit_borrowers %]
 <li><a id="renewpatron" href="/cgi-bin/koha/members/setstatus.pl?borrowernumber=[% patron.borrowernumber | html %]&amp;destination=[% destination | html %]&amp;reregistration=y">تجديد الممستفيد</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="renewpatron" title="ليس لديك صلاحية لتجديد المستفيدين">تجديد الممستفيد</a></li>
 [% END %]
 [% IF ( CAN_user_permissions ) %]
 <li><a id="patronflags" href="/cgi-bin/koha/members/member-flags.pl?member=[% patron.borrowernumber | html %]">اضبط الصلاحيات</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="patronflags" title="ليس لديك صلاحية لضبط الصلاحيات">اضبط الصلاحيات</a></li>
 [% END %]

 [% IF ( Koha.Preference('TwoFactorAuthentication') == 'enforced' || Koha.Preference('TwoFactorAuthentication') == 'enabled' ) && logged_in_user.borrowernumber == patron.borrowernumber %]
 <li><a id="twofa" href="/cgi-bin/koha/members/two_factor_auth.pl">إدارة الاستيثاق الثنائي</a></li>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers && useDischarge %]
 <li><a href="/cgi-bin/koha/members/discharge.pl?borrowernumber=[% patron.borrowernumber | uri %]">إخلاء الطرف</a></li>
 [% END %]

 [% IF Koha.Preference('RESTOAuth2ClientCredentials') %]
 [% IF CAN_user_superlibrarian OR loggedinusernumber == patron.borrowernumber %]
 <li><a id="apikeys" href="/cgi-bin/koha/members/apikeys.pl?patron_id=[% patron.borrowernumber | html %]">إدارة مفاتيح API</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="apikeys" title="ليس لديك صلاحية لإدارة مفاتيح API">إدارة مفاتيح API</a></li>
 [% END %]
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers %]
 <li><a id="sendwelcome" href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]&op=send_welcome">Send welcome notice</a></li>
 [% END %]

 [% IF CAN_user_borrowers_edit_borrowers && patron.category.effective_reset_password %]
 <li><a id="resetpassword" href="/cgi-bin/koha/members/notices.pl?borrowernumber=[% patron.borrowernumber | uri %]&op=send_password_reset">إرسال بريد إلكتروني لتعيين كلمة المرور</a></li>
 [% END %]

 [% IF CAN_user_borrowers_delete_borrowers %]
 [% IF ( patron.protected == 1 ) %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="deletepatron" title="المستفيد محمي">حذف</a></li>
 [% ELSE %]
 <li><a id="deletepatron" href="#">حذف</a></li>
 [% END %]
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="deletepatron" title="ليس لديك صلاحية لحذف المستفيدين">حذف</a></li>
 [% END %]
 [% SET adult_categories = Categories.scalar.all(category_type => 'A') %]
 [% IF adult_categories.count > 0 %]
 [% IF patron.is_child %]
 <li><a id="updatechild" href="#">تحديث المستفيد الطفل إلى مستفيد بالغ</a></li>
 [% ELSE %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="updatechild" title="المستفيد بالغ">تحديث المستفيد الطفل إلى مستفيد بالغ</a></li>
 [% END %]
 [% END %]
 [% IF Koha.Preference('intranetreadinghistory') %]
 [%IF ( privacy == 2 ) %]
 <li class="disabled"><a data-placement="left" data-toggle="tooltip" href="#" id="exportbarcodes" title="غير مسموح بواسطة إعدادات خصوصية المستفيد">تصدير الباركودات المعادة لهذا اليوم</a></li>
 [% ELSE %]
 <li><a id="exportcheckins" href="#">تصدير الباركودات المعادة لهذا اليوم</a></li>
 [% END %]
 [% END %]
 </ul>
 </div>
 [% END %]
</div>

<!-- Modal -->
<div id="add_message_form" class="modal" tabindex="-1" role="dialog" aria-labelledby="addnewmessageLabel" aria-hidden="true">
 <div class="modal-dialog modal-lg" role="document">
 <div class="modal-content modal-lg">
 <form method="post" action="/cgi-bin/koha/circ/add_message.pl" id="message_form" name="message_f">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="op" value="cud-add_message">
 <div class="modal-header">
 <button aria-label="إغلاق" class="closebtn" data-dismiss="modal" type="button">
 <span aria-hidden="true">&times;</span>
 </button>
 <h4>اترك رسالة</h4>
 </div>
 <div class="modal-body">
 <fieldset id="message_fieldset">
 <ol>
 <li class="form-group form-row">
 <label for="message_type" class="col-form-label">إضافة رسالة من أجل:</label>
 <select name="message_type" id="message_type" class="form-control">
 <option value="L">ملاحظة الموظفين الداخلية</option>
 <option value="B">أوباك- [% patron.firstname | html %] [% patron.surname | html %]</option>
 [% IF CAN_user_borrowers_send_messages_to_borrowers %]
 <option value="E">Email - email addresses of patron</option>
 [% END %]
 </select>
 </li>

 [% bor_notes = AuthorisedValues.Get( 'BOR_NOTES' ) %]
 [% IF bor_notes %]
 <li class="form-group form-row">
 <label for="select_patron_messages" class="col-form-label">ملاحظات محددة مسبقا: </label>
 <select name="type" id="select_patron_messages" class="form-control">
 <option value="">حدد ملاحظة</option>
 [% FOREACH bor_note IN bor_notes %]
 <option value="[% bor_note.lib | html %]">[% bor_note.lib | html %]</option>
 [% END %]
 </select>
 </li>
 [% END %]

 [% patron_letters = NoticeTemplates.GetByModule( 'add_message' ) %]
 [% IF patron_letters %]
 <li class="form-group form-row">
 <label for="select_patron_notice" class="col-form-lable" style="display:none;">Patron notice: </label>
 <select name="select_patron_notice" id="select_patron_notice" class="form-control" style="display:none;">
 <option value="">Select notice</option>
 [% FOREACH letter IN patron_letters %]
 <option value="[% letter.code | html %]">[% letter.name | html %]</option>
 [% END %]
 </select>
 </li>
 [% END %]

 <li class="form-group form-row" id="subject_form" style="display: none;">
 <label for="borrower_subject" class="col-form-label">الموضوع:</label>
 <input type="text" size="60" name="borrower_subject" class="form-control" id="borrower_subject"/>
 </li>
 <li class="form-group form-row">
 <label for="borrower_message" class="col-form-label" style="display: none;">Body:</label>
 <textarea cols="65" rows="5" name="borrower_message" class="form-control" id="borrower_message" ></textarea>
 </li>
 </ol>
 </fieldset>
 <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <input type="hidden" name="batch" value="[% batch | html %]" />
 <input type="hidden" name="branchcode" value="[% Branches.GetLoggedInBranchcode | html %]" />
 </div>
 <div class="modal-footer">
 <button class="btn btn-default approve" type="submit"><i class="fa fa-check"></i> حفظ</button>
 <button class="btn btn-default deny cancel" href="#" data-dismiss="modal" aria-hidden="true"><i class="fa fa-times"></i> إلغاء</button>
 </div>
 </form>
 </div>
 </div>
</div>
