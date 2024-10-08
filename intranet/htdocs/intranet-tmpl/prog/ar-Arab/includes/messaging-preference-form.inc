[% USE Koha %]
<!-- snippet for form to set borrower and patron category messaging preferences -->

<input type="hidden" name="modify" value="yes" />
<input type="hidden" name="borrowernumber" value="[% borrowernumber | html %]" />
 <table>
 <thead>
 <tr><th></th>
 <th>أيام سابقة</th>
 [% IF Koha.Preference('SMSSendDriver') %]<th>رسالة قصيرة</th>[% END %]
 [% IF Koha.Preference('TalkingTechItivaPhoneNotification') || Koha.Preference('PhoneNotification') %]<th>هاتف</th>[% END %]
 <th>البريد الإلكتروني</th>
 <th>الملخصات فقط <i class="fa fa-info-circle" data-placement="right" data-toggle="tooltip" id="info_digests" title="يمكنك طلب تلخيص أو تقليل عدد الرسائل. سيتم حفظ الرسائل وإرسالها كرسالة واحدة."></i></th>
 <!-- <th>RSS</th> -->
 </tr>
 </thead>
 <tbody>
 [% FOREACH messaging_preference IN messaging_preferences %]
 [% NEXT IF !Koha.Preference( 'ILLModule' ) && messaging_preference.message_name.match('^Ill_') %]
 [% NEXT IF messaging_preference.Auto_Renewals && Koha.Preference('AutoRenewalNotices') != 'preferences' %]
 <tr id="[% messaging_preference.message_name _ "_message" | lower | html %]">
 <td>[% IF ( messaging_preference.Item_Due ) %]<span>المادة مستحقة</span>
 [% ELSIF ( messaging_preference.Advance_Notice ) %]<span>إخطار متقدم</span>
 [% ELSIF ( messaging_preference.Hold_Filled ) %]<span>تم ملء الحجز</span>
 [% ELSIF ( messaging_preference.Hold_Reminder ) %]<span>تذكير الحجز</span>
 [% ELSIF ( messaging_preference.Item_Check_in ) %]<span>رد المادة</span>
 [% ELSIF ( messaging_preference.Item_Checkout ) %]
 [% IF Koha.Preference( 'RenewalSendNotice' ) %]
 <span>إعارة المواد وتجديدها</span>
 [% ELSE %]
 <span>إعارة المادة</span>
 [% END %]
 [% ELSIF ( messaging_preference.Ill_ready ) %]<span>الإعارة البينية جاهزة</span>
 [% ELSIF ( messaging_preference.Ill_unavailable ) %]<span>الإعارة البينية غير متاحة</span>
 [% ELSIF ( messaging_preference.Ill_update ) %]<span>تم تحديث الإعارة البينية</span>
 [% ELSIF ( messaging_preference.Auto_Renewals ) %]<span>تجديد تلقائي</span>
 [% ELSE %]<span>غير معروف</span>
 [% END %]
 </td>
 [% IF ( messaging_preference.takes_days ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 <select name="[% messaging_preference.message_attribute_id | html %]-DAYS" disabled="disabled">
 [% ELSE %]
 <select name="[% messaging_preference.message_attribute_id | html %]-DAYS">
 [% END %]
 [% FOREACH select_day IN messaging_preference.select_days %]
 [% IF ( select_day.selected ) %]<option value="[% select_day.day | html %]" selected="selected">[% select_day.day | html %]</option>[% ELSE %]
 <option value="[% select_day.day | html %]">[% select_day.day | html %]</option>
 [% END %]
 [% END %]
 </select>
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]

 [% IF Koha.Preference('SMSSendDriver') %]
 [% IF ( messaging_preference.transport_sms ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.transports_sms ) %]
 <input type="checkbox"
                 id="sms[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="sms" class="pmp_sms" checked="checked" disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
                 id="sms[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="sms" class="pmp_sms" disabled="disabled" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.transports_sms ) %]
 <input type="checkbox"
                 id="sms[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="sms" checked="checked" class="pmp_sms active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input type="checkbox"
                 id="sms[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="sms" class="pmp_sms active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]
 [% END %]

 [% IF Koha.Preference('TalkingTechItivaPhoneNotification') %]
 [% IF ( messaging_preference.transport_itiva ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.transports_itiva ) %]
 <input type="checkbox"
                 id="itiva[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="itiva" checked="checked" disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
                 id="itiva[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="itiva" disabled="disabled" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.transports_itiva ) %]
 <input type="checkbox"
                 id="itiva[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="itiva" checked="checked" class="pmp_phone active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input type="checkbox"
                 id="itiva[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="itiva" class="pmp_phone active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]
 [% ELSIF Koha.Preference('PhoneNotification') %]
 [% IF ( messaging_preference.transport_phone ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.transports_phone ) %]
 <input type="checkbox"
                 id="phone[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="phone" checked="checked" disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
                 id="phone[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="phone" disabled="disabled" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.transports_phone ) %]
 <input type="checkbox"
                 id="phone[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="phone" checked="checked" class="pmp_phone active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input type="checkbox"
                 id="phone[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="phone" class="pmp_phone active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]
 [% END %]

 [% IF ( messaging_preference.transport_email ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.transports_email ) %]
 <input type="checkbox"
                   id="email[% messaging_preference.message_attribute_id | html %]"
                   name="[% messaging_preference.message_attribute_id | html %]"
                   value="email" class="pmp_email" checked="checked" disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
                   id="email[% messaging_preference.message_attribute_id | html %]"
                   name="[% messaging_preference.message_attribute_id | html %]"
                   value="email" class="pmp_email" disabled="disabled" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.transports_email ) %]
 <input type="checkbox"
                 id="email[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="email" checked="checked" class="pmp_email active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input type="checkbox"
                 id="email[% messaging_preference.message_attribute_id | html %]"
                 name="[% messaging_preference.message_attribute_id | html %]"
                 value="email" class="pmp_email active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]

 [% IF ( messaging_preference.has_digest ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 [% IF ( messaging_preference.digest ) %]
 <input checked="checked" class="pmp_digest" data-toggle="tooltip" disabled="disabled" id="digest[% messaging_preference.message_attribute_id | html %]" name="digest" title="يجب تحديد وسيلة قابلة للتلخيص لتحديد الملخصات" type="checkbox" value="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input class="pmp_digest" data-toggle="tooltip" disabled="disabled" id="digest[% messaging_preference.message_attribute_id | html %]" name="digest" title="يجب تحديد وسيلة قابلة للتلخيص لتحديد الملخصات" type="checkbox" value="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% ELSE %]
 [% IF ( messaging_preference.digest ) %]
 <input checked="checked" class="pmp_digest active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" data-toggle="tooltip" id="digest[% messaging_preference.message_attribute_id | html %]" name="digest" title="يجب تحديد وسيلة قابلة للتلخيص لتحديد الملخصات" type="checkbox" value="[% messaging_preference.message_attribute_id | html %]" />
 [% ELSE %]
 <input class="pmp_digest active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" data-toggle="tooltip" id="digest[% messaging_preference.message_attribute_id | html %]" name="digest" title="يجب تحديد وسيلة قابلة للتلخيص لتحديد الملخصات" type="checkbox" value="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %]

<!-- [% IF ( messaging_preference.transport_rss ) %]
 <td>
 [% IF ( messaging_form_inactive ) %]
 <input type="checkbox"
 id="rss[% messaging_preference.message_attribute_id | html %]"
 name="[% messaging_preference.message_attribute_id | html %]"
 value="rss" [% messaging_preference.transport_rss | html %] disabled="disabled" />
 [% ELSE %]
 <input type="checkbox"
 id="rss[% messaging_preference.message_attribute_id | html %]"
 name="[% messaging_preference.message_attribute_id | html %]"
 value="rss" [% messaging_preference.transport_rss | html %] class="active_notify" data-attr-id="[% messaging_preference.message_attribute_id | html %]" />
 [% END %]
 </td>
 [% ELSE %]
 <td>-</td>
 [% END %] -->

 </tr>
 [% END %]
 </tbody>
 </table>
