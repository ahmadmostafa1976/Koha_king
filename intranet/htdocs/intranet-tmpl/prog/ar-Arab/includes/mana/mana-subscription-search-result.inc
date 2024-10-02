[% USE KohaDates %]
[% USE Koha %]
[% USE AuthorisedValues %]
[% USE Branches %]
[% USE raw %]

[% IF statuscode == "200" %]
 [% INCLUDE 'mana/mana-comment-status.inc' %]
 <div id="mana_results">
 <table id="mana_results_datatable">
 <thead>
 <tr>
 <th>تدمد</th>
 <th class="anti-the">عنوان</th>
 <th> منشور بواسطة </th>
 <th>التتابع</th>
 <th>نموذج الترقيم</th>
 <th title="عدد المكتبات التي تستخدم هذا النمط"># من المستخدمين</th>
 <th title="آخر مرة استخدمت فيها المكتبة هذا النمط">آخر استيراد</th>
 <th> التعليقات </th>
 [% UNLESS search_only %]
 <th class="NoSort noExport">الإجراءات</th>
 [% END %]
 </tr>
 </thead>
 <tbody>
 [% FOREACH subscription IN subscriptions %]
 [% UNLESS subscription.cannotdisplay %]
 [% IF subscription.nbofcomment > highWarned  %]
 <tr class="high-warned-row" id="row[% subscription.id | html %]" title="تم التبليغ عن هذا المورد أكثر من [% highWarned | html %] مرة، يرجى توخي الحذر!">
 [% ELSIF subscription.nbofcomment > warned  %]
 <tr class="warned-row" id="row[% subscription.id | html %]" title="تم التبليغ عن هذا المورد أكثر من [% warned | html %] مرة، يرجى توخي الحذر!">
 [% ELSIF subscription.nbofcomment > lowWarned  %]
 <tr class="highlighted-row" id="row[% subscription.id | html %]" title="تم التبليغ عن هذا المورد أكثر من [% lowWarned | html %] مرة، يرجى توخي الحذر!">
 [% ELSE %]
 <tr id="row[% subscription.id | html %]">
 [% END %]
 <input type="hidden" hidden class="rowid" value="[% subscription.id | html %]" />
 <td>[% IF ( subscription.issn ) %][% subscription.issn | html %][% END %]</td>
 <td>[% subscription.title | html %]</td>
 <td>[% IF ( subscription.publishercode ) %][% subscription.publishercode | html %][% END %]</td>
 <td>[% IF ( subscription.sfdescription ) %][% subscription.sfdescription | html %][% END %]</td>
 <td>[% IF ( subscription.numberingmethod ) %][% subscription.numberingmethod | html %][% END %]</td>
 <td>[% IF ( subscription.nbofusers ) %][% subscription.nbofusers | html %][% END %]</td>
 <td data-order="[% subscription.lastimport | html %]">[% subscription.lastimport | $KohaDates %]</td>
 <td>
 [% FOREACH comment IN subscription.comments %]
 [% comment.message | html %] ([% comment.nb | html %])<br />
 [% END %]
 </td>
 [% UNLESS search_only %]
 <td class="actions">
 <button class="btn btn-default btn-xs mana-use" data-subscription_id="[% subscription.id | html %]" id="mana-use-[% subscription.id | html %]"><i class="fa fa-download"></i> استيراد</button>
 <div class="dropup">
 <button type="button" class="btn btn-default btn-xs dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
 التقرير <span class="caret"></span>
 </button>
 <ul class="dropdown-menu pull-right mana-actions" id="mana-actions-[% subscription.id | html %]">
 [% IF ( subscription.comments.size ) %]
 [% FOREACH comment IN subscription.comments %]
 <li><a data-commentid="[% comment.id | html %]" data-resourceid="[% subscription.id | html %]" href="#">[% comment.message | html %] ([% comment.nb | html %])</a></li>
 [% END %]
 <li role="separator" class="divider"></li>
 [% END %]
 <li><a data-commentid="other" data-resourceid="[% subscription.id | html %]" href="#">تعليق جديد</a></li>
 </ul>
 </div>
 </td>
 [% END %]
 </tr>
 [% END %]
 [% END %]
 </tbody>
 </table>
 </div>
 <div id="new_mana_comment" style="display:none">
 <h4 id="mana_submit_comment"> يرجى إدخال تعليق جديد (الحد الأقصى 35 حرفًا)</h4>
 <form id="mana_comment_form" action="/cgi-bin/koha/serials/subscription-detail.pl" method="get">
 <input type="hidden" id="mana-resource" value="subscription" />
 <input type="hidden" id="mana-resource-id" value="[% mana_id | html %]" />
 <input type="text" maxlength="35" size="35" id="mana-comment" required="required" />
 <input type="hidden" id="selected_id" value="" />
 <div class="action">
 <button id="mana-send-comment">تقديم</button>
 <a href="#" class="cancel" id="mana-comment-close">إلغاء</a>
 </div>
 </form>
 </div>
[% ELSE %]
 <h4>يفشل بحث مانا بالرمز: [% statuscode | html %] </h4>
[% END %]
