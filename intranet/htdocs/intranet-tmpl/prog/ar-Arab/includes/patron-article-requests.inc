[% USE Context %]
[% SET current_article_requests = Context.Scalar( Context.Scalar( patron, 'article_requests' ), 'filter_by_current' ) %]
[% IF current_article_requests.count > 0 %]
 <table id="article-requests-table" class="table table-bordered table-striped">
 <thead>
 <tr>
 <th class="article-request-record-title anti-the">عنوان التسجيلة</th>
 <th class="article-request-created_on psort">موضوع على</th>
 <th class="article-request-title anti-the">عنوان</th>
 <th class="article-request-author">مؤلف</th>
 <th class="article-request-volume">مجلد</th>
 <th class="article-request-issue">عدد</th>
 <th class="article-request-date">التاريخ</th>
 <th class="article-request-toc" title="جدول المحتويات">جدول المحتويات</th>
 <th class="article-request-pages">صفحات</th>
 <th class="article-request-chapters">فصول</th>
 <th class="article-request-notes">ملاحظات</th>
 <th class="article-request-format">تنسيق</th>
 <th class="article-request-status">حالة</th>
 <th class="article-request-branchcode">مكتبة السحب</th>
 </tr>
 </thead>

 <tbody>
 [% FOREACH ar IN current_article_requests %]
 <tr>
 <td class="article-request-record-title">
 <a class="article-request-record-link-title" href="/cgi-bin/koha/circ/request-article.pl?biblionumber=[% ar.biblionumber | html %]">
 [% ar.biblio.title | html %]
 [% ar.item.enumchron | html %]
 </a>
 [% ar.biblio.author | html %]
 [% IF ar.itemnumber %] <em>(فقط [% ar.item.barcode | html %])</em>[% END %]
 </td>

 <td class="article-request-created_on">
 [% ar.created_on | $KohaDates %]
 </td>

 <td class="article-request-title">
 [% ar.title | html %]
 </td>

 <td class="article-request-author">
 [% ar.author | html %]
 </td>

 <td class="article-request-volume">
 [% ar.volume | html %]
 </td>

 <td class="article-request-issue">
 [% ar.issue | html %]
 </td>

 <td class="article-request-date">
 [% ar.date | html %]
 </td>

 <td class="article-request-toc">
 [% IF ar.toc_request %]<span>نعم</span>[% END %]
 </td>

 <td class="article-request-pages">
 [% ar.pages | html %]
 </td>

 <td class="article-request-chapters">
 [% ar.chapters | html %]
 </td>

 <td class="article-request-patron-notes">
 [% ar.patron_notes | html %]
 </td>

 <td class="article-request-format">
 [% IF ar.format == 'PHOTOCOPY' %]<span>نسخ</span>
 [% ELSIF ar.format == 'SCAN' %]<span>مسح ضوئي</span>
 [% END %]
 </td>

 <td class="article-request-status">
 [% IF ar.status == 'PENDING' %]
 <span>في الانتظار</span>
 [% ELSIF ar.status == 'PROCESSING' %]
 <span>جاري المعالجة</span>
 [% ELSIF ar.status == 'COMPLETED' %]
 <span>اكتمل</span>
 [% ELSIF ar.status == 'CANCELED' %]
 <span>ملغي</span>
 [% END %]
 </td>

 <td class="article-request-branchcode">
 [% ar.branch.branchname | html %]
 </td>
 </tr>
 [% END %]
 </tbody>
 </table>
 [% ELSE %]
 <span>لا توجد طلبات مقال حالية للمستفيد.</span>
 [% END %]
