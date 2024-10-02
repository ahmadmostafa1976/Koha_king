[% USE raw %]
[% IF ( PAGE_NUMBERS ) %]
 <nav aria-label="ترقيم صفحات نتائج البحث" class="pagination pagination-sm noprint">
 [% IF hits_to_paginate < total %]
 <span class="h6">[% hits_to_paginate | html %] من [% total | html %] النتائج التي تم تحميلها، قم بتنقيح بحثك لعرض تسجيلات أخرى</span>
 [% END %]
 <ul class="pagination">
 [% IF ( previous_page_offset.defined ) %]
 <li class="page-item">
 <a aria-label="اذهب إلى الصفحة الأولى" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]"><i class="fa fa-fw fa-angle-double-left" aria-hidden="true"></i> أولا</a>
 </li>
 <li class="page-item">
 <a aria-label="اذهب إلى الصفحة السابقة" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% previous_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]"> <i class="fa fa-fw fa-angle-left" aria-hidden="true"></i> السابق</a>
 </li>
 [% END %]
 [% FOREACH PAGE_NUMBER IN PAGE_NUMBERS %]
 [% IF ( PAGE_NUMBER.highlight ) %]
 <li class="page-item disabled">
 <a aria-current="true" aria-disabled="true" aria-label="الصفحة الحالية: صفحة [% PAGE_NUMBER.pg | html %]" class="page-link" href="#">[% PAGE_NUMBER.pg | html %]</a>
 </li>
 [% ELSE %]
 <li class="page-item">
 <a aria-label="اذهب إلى صفحة [% PAGE_NUMBER.pg | html %]" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% PAGE_NUMBER.offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">[% PAGE_NUMBER.pg | html %]</a>
 </li>
 [% END %]
 [% END %]
 [% IF ( next_page_offset ) %]
 <li class="page-item">
 <a aria-label="اذهب إلى الصفحة الرئيسية" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% next_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">التالي <i class="fa fa-fw fa-angle-right" aria-hidden="true"></i></a>
 </li>
 <li class="page-item">
 <a aria-label="اذهب إلى الصفحة الأخيرة" class="page-link" href="/cgi-bin/koha/opac-search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&offset=[% last_page_offset | uri %][% IF ( sort_by ) %]&sort_by=[% sort_by | uri %][% END %][% IF results_per_page %]&count=[% results_per_page | uri %][% END %]">آخر <i class="fa fa-fw fa-angle-double-right" aria-hidden="true"></i></a>
 </li>
 [% END %]
 </ul>
 </nav>
[% END %]
