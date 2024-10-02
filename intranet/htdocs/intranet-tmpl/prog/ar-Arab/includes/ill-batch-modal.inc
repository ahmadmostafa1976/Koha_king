[% PROCESS 'html_helpers.inc' %]
<div id="ill-batch-details" style="display:none"></div>
<div id="ill-batch-modal" class="modal fade" tabindex="-1" role="dialog" aria-labelledby="ill-batch-modal-label" aria-hidden="true">
 <div class="modal-dialog modal-lg">
 <div class="modal-content">
 <div class="modal-header">
 <button type="button" class="closebtn" data-dismiss="modal" aria-hidden="true">×</button>
 <h3 id="ill-batch-modal-label"></h3>
 </div>
 <div class="modal-body">
 <div id="batch-form">
 <form method="get" id="new-batch-form">
 <fieldset class="rows">
 <legend id="legend">تفاصيل الدفعة</legend>
 <ol>
 <li id="batch_name">
 <label class="required" for="name">اسم الدفعة:</label>
 <input type="text" autocomplete="off" name="name" id="name" type="text"
                                    value="" />
 </li>
 <li id="batch_patron">
 <label class="required" for="batchcardnumber">رقم البطاقة أو اسم المستخدم أو اسم العائلة:</label>
 <input type="text" autocomplete="off" name="batchcardnumber" id="batchcardnumber" type="text" value="" />
 <span id="patron_link"></span>
 </li>
 <li id="batch_branch">
 <label class="required" for="branchcode">المكتبة:</label>
 <select id="branchcode" name="branchcode">
 [% PROCESS options_for_libraries libraries => Branches.all( selected => branchcode ) %]
 </select>
 </li>
 <li id="batch_status_code" style="display:none">
 <label class="required" for="status_code">حالة:</label>
 <select id="status_code" name="status_code"></select>
 </li>
 </ol>
 </fieldset>
 <fieldset id="add_batch_items" class="rows" style="display:none">
 <legend id="legend">إضافة مواد بالدفعة</legend>
 <div id="textarea-metadata">
 <div id="supported">المعرفات المدعومة: <span id="supported_identifiers"></span></div>
 <div id="row_count">عدد الصفوف: <span id="row_count_value"></span></div>
 </div>
 <div id="textarea-errors" style="display:none" class="error">
 <div id="duplicates" style="display:none">تم العثور على التكرارات التالية، وتم إلغاء تكرارها: <span id="dupelist"></span></div>
 <div id="badidentifiers" style="display:none">تم العثور على المعرفات غير المعروفة التالية، ولم يكن من الممكن تحديد نوعها: <span id="badids"></span></div>
 </div>
 <ol>
 <li>
 <textarea id="identifiers_input" placeholder="قم بإدخال المعرفات، واحد في كل سطر"></textarea>
 </li>
 <li id="process-button">
 <button id="process_button" disabled aria-disabled="true" type="button">معرفات العملية</button>
 </li>
 </ol>
 </fieldset>
 </form>
 <div id="create-progress" class="alert alert-info" role="alert" style="display:none">
 <span id="progress-label"><strong></strong></span> - المواد التي تمت معالجتها: <span id="processed_count"></span> من إجمالي <span id="processed_total"></span>. المواد التي فشلت: <span id="processed_failed"></span>.
 <div class="progress">
 <div id="processed_progress_bar" class="progress-bar" role="progressbar" aria-valuenow="0" aria-valuemin="0" aria-valuemax="100" style="min-width: 2em;">
 0% </div>
 </div>
 </div>
 <table id="identifier-table" style="display:none">
 <thead>
 <tr id="identifier-table-header">
 <th scope="col">نوع المعرف</th>
 <th scope="col">قيمة المعرف</th>
 <th scope="col">الميتاداتا</th>
 <th scope="col">معرّف الطلب</th>
 <th scope="col">حالة الطلب</th>
 [% IF Koha.Preference('ILLCheckAvailability') %]
 <th scope="col">متاح</th>
 [% END %]
 <th scope="col"></th>
 </tr>
 </thead>
 <tbody id="identifier-table-body">
 </tbody>
 </table>
 </div>
 <div id="create-requests" style="display:none">
 <button aria-label="إضافة مواد إلى دفعة" class="btn btn-primary" id="create-requests-button" type="button">إضافة مواد إلى دفعة</button>
 </div>
 </div>
 <div class="modal-footer">
 <div id="lhs">
 <button class="btn btn-default" data-dismiss="modal" aria-hidden="false">إلغاء</button>
 </div>
 <div id="rhs">
 <button id="button_create_batch" class="btn btn-default" aria-hidden="true" disabled>متابعة</button>
 <button id="button_finish" disabled type="button" class="btn btn-default" aria-hidden="true">إنهاء وعرض الدفعة</button>
 </div>
 </div>
 </div>
 </div>
</div>
