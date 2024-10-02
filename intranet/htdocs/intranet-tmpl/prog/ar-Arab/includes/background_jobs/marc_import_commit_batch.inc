[% USE Koha %]

[% BLOCK report %]
 [% SET report = job.report %]
 [% IF report %]
 [% IF job.status == 'finished' %]
 <div class="dialog message">استيراد مكتمل للتسجيلات</div>
 [% END %]
 <table>
 <tr>
 <td>عدد التسجيلات التى تمت إضافتها</td>
 <td>[% report.num_added | html %]</td>
 </tr>
 <tr>
 <td>عدد التسجيلات التى تم تحديثها</td>
 <td>[% report.num_updated | html %]</td>
 </tr>
 <tr>
 <td>عدد التسجيلات التي تم تجاهلها</td>
 <td>[% report.num_ignored | html %]</td>
 </tr>
 <tr>
 <td>عدد المواد التي تمت إضافتها</td>
 <td>[% report.num_items_added | html %]</td>
 </tr>
 <tr>
 <td>عدد المواد التي تم استبدالها</td>
 <td>[% report.num_items_replaced | html %]</td>
 </tr>
 <tr>
 <td>عدد المواد التي تم تجاهلها</td>
 <td>[% report.num_items_errored | html %]</td>
 </tr>
 </table>
 <p>
 <a href="/cgi-bin/koha/tools/manage-marc-import.pl?import_batch_id=[% report.import_batch_id | url %]">أدر الدفعة التي تم استيرادها</a>
 </p>
 [% END %]
[% END %]

[% BLOCK detail %]
[% END %]

[% BLOCK js %]
[% END %]
