[% IF renew_results && renew_results.size > 0 %]
 <div class="alert">
 تم دفع الغرامات على المواد التالية، نتائج التجديد معروضة أدناه: [% FOREACH result IN renew_results %] [% IF result.success %] <p>[% INCLUDE 'biblio-title.inc' biblio=result.item.biblio %] ( [% result.item.barcode | html %] ): تم تجديده - مستحق [% result.info | html %]</p>
 [% ELSE %]
 <p>[% INCLUDE 'biblio-title.inc' biblio=result.item.biblio %] ( [% result.item.barcode | html %] ): لم يتم تجديده - [% INCLUDE 'renew_strings.inc' error=result.info %]</p>
 [% END %]
 [% END %]
 </div>
[% END %]
