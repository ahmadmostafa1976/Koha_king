[% USE raw %]
[% IF ( PAGE_NUMBERS ) %]<nav><ul class="pagination">
 [% IF hits_to_paginate < total %]<h6>[% hits_to_paginate | html %] من [% total | html %] النتائج التي تم تحميلها، قم بتنقيح بحثك لعرض تسجيلات أخرى</h6>[% END %]
 [% IF ( previous_page_offset.defined ) %]
 <li><a class="nav" href="/cgi-bin/koha/catalogue/search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %][% IF ( sort_by ) %]&amp;sort_by=[% sort_by |url %][% END %][% IF results_per_page %]&amp;count=[% results_per_page | html %][% END %]"><i class="fa fa-fw fa-angle-double-left"></i> أولا</a></li>
 <!-- Row of numbers corresponding to search result pages -->
 <li><a class="nav" href="/cgi-bin/koha/catalogue/search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&amp;offset=[% previous_page_offset | html %][% IF ( sort_by ) %]&amp;sort_by=[% sort_by |url %][% END %][% IF results_per_page %]&amp;count=[% results_per_page | html %][% END %]"><i class="fa fa-fw fa-angle-left"></i> السابق</a></li>
 [% END %]
 [% FOREACH PAGE_NUMBER IN PAGE_NUMBERS %]
 [% IF ( PAGE_NUMBER.highlight ) %]
 <li class="active"><span>[% PAGE_NUMBER.pg | html %]</span></li>
 [% ELSE %]
 <li><a class="nav" href="/cgi-bin/koha/catalogue/search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&amp;offset=[% PAGE_NUMBER.offset | html %][% IF ( sort_by ) %]&amp;sort_by=[% sort_by |url %][% END %][% IF results_per_page %]&amp;count=[% results_per_page | html %][% END %]">[% PAGE_NUMBER.pg | html %]</a></li>
 [% END %]
 [% END %]
 [% IF ( next_page_offset ) %]
 <li><a class="nav" href="/cgi-bin/koha/catalogue/search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&amp;offset=[% next_page_offset | html %][% IF ( sort_by ) %]&amp;sort_by=[% sort_by |url %][% END %][% IF results_per_page %]&amp;count=[% results_per_page | html %][% END %]">التالي <i class="fa fa-fw fa-angle-right"></i></a></li>
 <li><a class="nav" href="/cgi-bin/koha/catalogue/search.pl?[% query_cgi | $raw %][% limit_cgi | $raw %]&amp;offset=[% last_page_offset | html %][% IF ( sort_by ) %]&amp;sort_by=[% sort_by |url %][% END %][% IF results_per_page %]&amp;count=[% results_per_page | html %][% END %]">آخر <i class="fa fa-fw fa-angle-double-right"></i></a></li>
 [% END %]
</ul></nav>[% END %]
