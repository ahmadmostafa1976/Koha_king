[% SWITCH Koha.Preference('CSVDelimiter') %]
 [% CASE '#' %]<span>نص مفصول بعلامة (#) (.csv)</span>
 [% CASE ',' %]<span>نص مفصول بفاصلة (.csv)</span>
 [% CASE '/' %]<span>نص مفصول بعلامة مائلة (.csv)</span>
 [% CASE ';' %]<span>نص مفصول بفاصلة منقوطة (.csv)</span>
 [% CASE '\\' %]<span>نص مفصول بخطوط مائلة (.csv)</span>
 [% CASE 'tabulation' %]<span>نص مفصول بعلامة العمود (.csv)</span>
[% END %]
