[% USE Koha %]
[% PROCESS 'modal-claims.inc' %]
[% INCLUDE 'format_price.inc' %]

[% IF ( issuecount ) %]
 <div id="issues-table-loading-message">
 <p>
 <a id="issues-table-load-now-button" href="#" class="btn btn-default"><i class="fa fa-book"></i> عرض الإعارات</a>
 [% SET LoadCheckoutsTableDelay = Koha.Preference('LoadCheckoutsTableDelay') %]
 [% IF LoadCheckoutsTableDelay && page == 'circulation' %]
 <span id="issues-table-load-delay">
 <i id="issues-table-load-delay-spinner" class="fa fa-spinner fa-pulse fa-fw"></i>
 <span id="issues-table-load-delay-message">سيظهر جدول الإعارات تلقائياً خلال [% LoadCheckoutsTableDelay | html %] ثانية...</span>
 <span>
 [% END %]
 </p>
 </div>
 <form name="issues" action="/cgi-bin/koha/tools/export.pl" method="post">
 [% INCLUDE 'csrf-token.inc' %]
 <table id="issues-table" style="width: 100% !Important; display: none;">
 <thead>
 <tr>
 <th scope="col">&nbsp;</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">تاريخ الإستحقاق</th>
 <th scope="col">تاريخ الإستحقاق</th>
 <th scope="col">عنوان</th>
 <th scope="col">نوع المادة على مستوى التسجيلة</th>
 <th scope="col">نوع المادة</th>
 <th scope="col">المجموعة</th>
 <th scope="col">الموقع</th>
 <th scope="col">المكتبة الرئيسية</th>
 <th scope="col">&nbsp;</th>
 <th scope="col">الإعارة في</th>
 <th scope="col">تمت الإعارة من</th>
 <th scope="col">رقم الاستدعاء</th>
 <th scope="col">رقم النسخة</th>
 <th scope="col">فرض رسم</th>
 <th scope="col">غرامة</th>
 <th scope="col">السعر</th>
 <th scope="col">تجديد <p class="column-tool"><a href="#" id="CheckAllRenewals">تحديد الكل</a> | <a href="#" id="UncheckAllRenewals">لا شيء</a></p></th>
 <th scope="col">الرد <p class="column-tool"><a href="#" id="CheckAllCheckins">تحديد الكل</a> | <a href="#" id="UncheckAllCheckins">لا شيء</a></p></th>
 <th scope="col">إدعاء إعادة</th>
 <th scope="col">تصدير <p class="column-tool"><a href="#" id="CheckAllExports">تحديد الكل</a> | <a href="#" id="UncheckAllExports">لا شيء</a></p></th>
 </tr>
 </thead>
 [% INCLUDE 'checkouts-table-footer.inc' %]
 </table>

 <label for="issues-table-load-immediately">عرض الإعارات تلقائياً دائماً</label>
 <input id="issues-table-load-immediately" type="checkbox" />

 <div id="issues-table-actions" style="display: none;">
 <fieldset class="action">
 [% IF ( CAN_user_circulate_override_renewals ) %]
 [% IF Koha.Preference( 'AllowRenewalLimitOverride' ) || Koha.Preference( 'AllowRenewalOnHoldOverride' ) %]
 <label for="override_limit">تخطي قيود التجديد:</label>
 <input type="checkbox" name="override_limit" id="override_limit" value="1" />
 [% END %]
 [% END %]
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% IF Koha.Preference( 'UnseenRenewals' ) %]
 <label id="renew_as_unseen_label" for="override_limit">تجديد كـ &quot;غير مرئي&quot; عند الاقتضاء:</label>
 <input type="checkbox" name="renew_as_unseen" id="renew_as_unseen_checkbox" value="1" />
 [% END %]
 <button class="btn btn-default" id="CheckinChecked" disabled="disabled"><i class="fa fa-download"></i> رد المواد المحددة</button>
 <button class="btn btn-default" id="RenewChecked" disabled="disabled"><i class="fa fa-retweet"></i> تجديد المواد المحددة</button>
 <button class="btn btn-default" id="RenewAll"><i class="fa fa-book"></i> تجديد الكل</button>
 [% END %]
 </fieldset>

 [% IF Koha.Preference('ExportCircHistory') %]
 <fieldset>
 <label for="issues-table-output-format"><strong>تصدير الإعارات باستخدام التنسيق:</strong></label>
 <select name="issues-table-output-format" id="issues-table-output-format">
 <option value="iso2709_995">مارك بمواد</option>
 <option value="iso2709">مارك بدون مواد</option>
 [% IF csv_profiles.count %]
 <option value="csv">CSV</option>
 [% END %]
 </select>

 [% IF csv_profiles.count %]
 <select name="csv_profile_id">
 [% FOREACH csv_profile IN csv_profiles %]
 <option value="[% csv_profile.export_format_id | html %]">[% csv_profile.profile | html %]</option>
 [% END %]
 </select>
 [% END %]
 <label for="export_items_bundle_contents">تصدير محتويات حزمة المواد</label> <input type="checkbox" name="export_items_bundle_contents" id="export_items_bundle_contents">
 <label for="export_remove_fields">لا تقم بتصدير الحقول:</label> <input id="export_remove_fields" name="export_remove_fields" title="استخدم لتصديرات مارك" type="text" value="[% Koha.Preference('ExportRemoveFields') | html %]" />
 <input type="hidden" name="op" value="cud-export" />
 <input type="hidden" id="output_format" name="output_format" value="iso2709" />
 <input type="hidden" id="dont_export_item" name="dont_export_item" value="0" />
 <input type="hidden" id="record_type" name="record_type" value="bibs" />
 <button class="btn btn-default btn-sm" id="export_submit"><i class="fa fa-download"></i> تصدير</button>
 </fieldset>
 [% END %]
 </div>
 </form>
[% ELSE %]
 <p>المستفيد ليس لديه شيء مُعار.</p>
[% END %]

<!-- Claims Returned Modal -->
[% PROCESS 'modal-claims-display' %]
