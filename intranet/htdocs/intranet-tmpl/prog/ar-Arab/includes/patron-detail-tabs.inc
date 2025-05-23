<!-- patron-detail-tabs.inc -->
[% USE raw %]
[% PROCESS 'html_helpers.inc' %]
[% WRAPPER tabs id= "finesholdsissues" %]
 [% WRAPPER tabs_nav %]
 [% WRAPPER tab_item tabname= "checkouts" bt_active= 1 %]
 <span>الإعارات (<span class="checkout_count">[% issuecount || 0 | html %]</span>)</span>
 [% END %]

 [% IF relatives_issues_count %]
 [% WRAPPER tab_item tabname= "relatives-issues" %]
 <span>إعارات الأقارب ([% relatives_issues_count | html %])</span>
 [% END %]
 [% END %]

 [% IF ( fines ) %]
 [% WRAPPER tab_item tabname= "finesandcharges" %]
 <span>الرسوم ([% fines | $Price %])</span>
 [% END %]
 [% END %]

 [% IF ( guarantees_fines ) %]
 [% WRAPPER tab_item tabname= "guarantees_finesandcharges" %]
 <span>رسوم المكفول ([% guarantees_fines | $Price %])</span>
 [% END %]
 [% END %]

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% WRAPPER tab_item tabname= "holds" %]
 <span>الحجوزات ([% holds_count || 0 | html %])</span>
 [% END %]
 [% WRAPPER tab_item tabname="bookings" %]
 [% SET bookings_count = patron.bookings.filter_by_active.count %]
 <span class="bookings_count">Bookings ([% bookings_count || 0 | html %])</span>
 [% END %]
 [% END %]

 [% IF Koha.Preference('UseRecalls') %]
 [% WRAPPER tab_item tabname= "recalls" %]
 <span>الاستدعاءات ([% recalls.count || 0 | html %])</span>
 [% END %]
 [% END %]

 [% IF Koha.Preference('ArticleRequests') %]
 [% SET article_requests = Context.Scalar( Context.Scalar( patron, 'article_requests' ), 'filter_by_current') %]
 [% WRAPPER tab_item tabname= "article-requests" %]
 <span>طلبات المقال  ([% article_requests.count || 0 | html %])</span>
 [% END %]
 [% END %]

 [% IF Koha.Preference('ClaimReturnedLostValue') || Koha.Preference('BundleLostValue') %]
 [% WRAPPER tab_item tabname= "return-claims" %]
 <span>المطالبات</span>
 [% IF ( patron.return_claims.count ) %]
 ([% IF patron.return_claims.resolved.count == 0 %]
 <span class="label label-default" id="return-claims-count-resolved" title="مطالبات محلولة">[% patron.return_claims.resolved.count | html %]</span>
 [% ELSE %]
 <span class="label label-success" id="return-claims-count-resolved" title="مطالبات محلولة">[% patron.return_claims.resolved.count | html %]</span>
 [% END %]
 [% IF patron.return_claims.unresolved.count == 0 %]
 <span class="label label-default" id="return-claims-count-unresolved" title="إدعاءات غير محلولة">[% patron.return_claims.unresolved.count | html %]</span>
 [% ELSE %]
 <span class="label label-warning" id="return-claims-count-unresolved" title="إدعاءات غير محلولة">[% patron.return_claims.unresolved.count | html %]</span>
 [% END %])
 [% ELSE %]
 [% no_claims = 0 %]
 (<span class="label label-default" id="return-claims-count-resolved" title="مطالبات محلولة">[% no_claims | html %]</span>
 <span class="label label-default" id="return-claims-count-unresolved" title="إدعاءات غير محلولة">[% no_claims | html %]</span>)
 [% END # /IF patron.return_claims.count %]
 [% END # /WRAPPER tab_item return-claims %]
 [% END %]

 [% WRAPPER tab_item tabname= "reldebarments" %]
 <span>القيود ([% patron.restrictions.count || 0 | html %])</span>
 [% END %]

 [% SET enrollments = patron.get_club_enrollments %]
 [% SET enrollable  = patron.get_enrollable_clubs(0) %] <!-- 0 => not OPAC -->
 [% IF CAN_user_clubs && ( enrollable.count || enrollments.count ) %]
 [% WRAPPER tab_item tabname= "clubs" %]
 <span>الأندية ([% enrollments.count | html %]/[% enrollable.count | html %])</span>
 [% END %]
 [% END %]

 [% IF CAN_user_tools_manage_patron_lists || patron_lists_count %]
 [% WRAPPER tab_item tabname="pat_lists" %]
 <span>قوائم المستفيد  ([% patron_lists_count | html %])</span>
 [% END %]
 [% END %]
 [% END # /WRAPPER tabs_nav %]


 [% WRAPPER tab_panels %]
 [% WRAPPER tab_panel tabname="checkouts" bt_active= 1 %]
 [% INCLUDE "checkouts-table.inc" %]
 [% END # /tab_panel# %]

 [% WRAPPER tab_panel tabname="relatives-issues" %]
 [% INCLUDE "relatives-issues-table.inc" %]
 [% END # /tab_panel# %]

 [% WRAPPER tab_panel tabname="finesandcharges" %]
 [% IF ( fines ) %]
 <p>إجمالي المستحقات: [% fines | $Price %]</p>
 [% ELSE %]
 <p>لا توجد غرامات غير مدفوعة</p>
 [% END %]
 [% END # /tab_panel# %]

 [% IF ( guarantees_fines ) %]
 [% WRAPPER tab_panel tabname="guarantees_finesandcharges" %]
 <table id="tguaranteesfines">
 <thead>
 <tr>
 <th>مكفول</th>
 <th>المبلغ الغير مسدد</th>
 </tr>
 </thead>
 [% FOREACH guarantee IN guarantees %]
 <tr>
 <td>[% INCLUDE 'patron-title.inc' patron=guarantee hide_patron_infos_if_needed=1 %]</td>
 [% IF logged_in_user.can_see_patron_infos( guarantee ) %]
 <td>[% guarantee.account.balance | $Price %]</td>
 [% ELSE %]
 <td>-</td>
 [% END %]
 </tr>
 [% END %]
 <tfoot>
 <td>إجمالي المستحقات</td>
 <td>[% guarantees_fines | $Price %]</td>
 </tfoot>
 </table>
 [% END # /tab_panel# %] [% END # /tab_panel# %] [% IF CAN_user_clubs && ( enrollments.count || enrollable.count ) %] [% WRAPPER tab_panel tabname="clubs" %] جاري التحميل... [% END # /tab_panel# %] [% END %] [% IF CAN_user_tools_manage_patron_lists || patron_lists_count %] [% WRAPPER tab_panel tabname="pat_lists" %] جاري التحميل... [% END # /tab_panel# %] [% END %] [% WRAPPER tab_panel tabname="reldebarments" %] [% INCLUDE 'patron-restrictions-tab.inc' %] [% END # /tab_panel# %] [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %] [% WRAPPER tab_panel tabname="holds" %] [% IF ( holds_count ) %] <form action="/cgi-bin/koha/reserve/modrequest.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <input type="hidden" name="from" value="circ" />
 <table id="holds-table" style="width: 100% !Important;">
 <thead>
 <tr>
 <th>تاريخ حجز</th>
 <th class="anti-the">عنوان</th>
 <th>رقم الاستدعاء</th>
 <th>نوع المادة</th>
 <th>الباركود</th>
 <th>التقط من</th>
 <th>انتهاء</th>
 <th>الأولوية</th>
 <th>ملاحظات</th>
 <th>حذف؟</th>
 <th>تعليق؟</th>
 <th>حالة</th>
 </tr>
 </thead>
 </table>

 <fieldset class="action">
 <input class="cancel" name="submit" type="submit" value="إلغاء الحجوزات المحددة" />

 [% SET hold_cancellation = AuthorisedValues.GetAuthValueDropbox('HOLD_CANCELLATION') %]
 [% IF hold_cancellation.count %]
 <label for="cancellation-reason">سبب الإلغاء:</label>
 <input type="hidden" name="op" value="cud-cancelall" />
 <select name="cancellation-reason">
 <option value="">لم يتم إبداء أسباب</option>
 [% FOREACH reason IN hold_cancellation %]
 <option value="[% reason.authorised_value | html %]">[% reason.lib | html %]</option>
 [% END %]
 </select>
 [% END %]
 </fieldset>
 </form>

 [% IF Koha.Preference('SuspendHoldsIntranet') %]
 <form action="/cgi-bin/koha/reserve/modrequest_suspendall.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <fieldset class="action">
 <input type="hidden" name="op" value="cud-suspendall" />
 <input type="hidden" name="from" value="[% patronpage | html %]" />
 <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <input class="btn btn-primary" type="submit" value="تعليق كل الحجوزات" />

 [% IF Koha.Preference('AutoResumeSuspendedHolds') %]
 <label for="suspend_until">حتى</label>
 <input type="text" size="10" id="suspend_until" name="suspend_until" class="flatpickr" data-flatpickr-futuredate="true"/>
 <span class="hint">حدد التاريخ الذي سيتم به الإستئناف [% INCLUDE 'date-format.inc' %]:  </span>
 [% END %]
 </fieldset>
 </form>

 <form action="/cgi-bin/koha/reserve/modrequest_suspendall.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <fieldset class="action">
 <input type="hidden" name="op" value="cud-unsuspendall" />
 <input type="hidden" name="from" value="borrower" />
 <input type="hidden" name="borrowernumber" value="[% patron.borrowernumber | html %]" />
 <input type="hidden" name="suspend" value="0" />
 <input class="btn btn-primary" type="submit" value="استئناف جميع الحجوزات المعلقة" />
 </fieldset>
 </form>
 [% END # IF SuspendHoldsIntranet %]

 [% ELSE %]
 <p>المستفيد ليس لديه شيء في الحجز.</p>
 [% END %]
 [% END # /tab_panel#holds %]

 [% WRAPPER tab_panel tabname="bookings" %]
 [% IF ( bookings_count ) %]
 <table id="bookings_table" style="width: 100% !Important;"></table>
 [% ELSE %]
 <p>Patron has nothing booked.</p>
 [% END %]
 [% END %]
 [% END %]

 [% IF Koha.Preference('UseRecalls') %]
 [% WRAPPER tab_panel tabname="recalls" %]
 [% INCLUDE 'recalls.inc' %]
 [% END # /tab_panel# %]
 [% END %]

 [% IF Koha.Preference('ClaimReturnedLostValue') || Koha.Preference('BundleLostValue') %]
 [% WRAPPER tab_panel tabname="return-claims" %]
 [% INCLUDE 'patron-return-claims.inc' %]
 [% END # /tab_panel# %]
 [% END %]

 [% IF Koha.Preference('ArticleRequests') %]
 [% WRAPPER tab_panel tabname="article-requests" %]
 [% INCLUDE 'patron-article-requests.inc' %]
 [% END %]
 [% END # /tab_panel# %]

 [% END # /WRAPPER tab_panels %]
[% END # /WRAPPER tabs %]
<!-- /patron-detail-tabs.inc -->
