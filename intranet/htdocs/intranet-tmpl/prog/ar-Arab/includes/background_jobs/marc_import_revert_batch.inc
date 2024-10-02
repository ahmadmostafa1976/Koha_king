[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">نجاح: تم إرجاع الاستيراد</div>
 [% END %]
 <table>
 <tr>
 <td>عدد التسجيلات التي تم حذفها</td>
 <td>[% report.num_deleted | html %]</td>
 </tr>
 <tr>
 <td>عدد التسجيلات التي تم إرجاعها</td>
 <td>[% report.num_reverted | html %]</td>
 </tr>
 <tr>
 <td>عدد التسجيلات التي تم تجاهلها</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>عدد المواد التي تم حذفها</td>
 <td>[% report.num_items_deleted | html %]</td>
 </tr>
 <tr>
 <td>عدد الأخطاء</td>
 <td>[% report.num_errors | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">أدر الدفعة التي تم إرجاعها</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
