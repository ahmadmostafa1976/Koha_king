[% USE Koha %]
[% BLOCK 'alt-contact-style' %]
 <fieldset class="rows" id="memberentry_altaddress">
 <legend class="expanded" id="alt_contact_lgd">
 <i class="fa fa-caret-down"></i>
 Alternate contact
 </legend>
 <ol>
 [% IF Koha.Preference( 'AddressFormat' ) %]
 [% PROCESS "member-alt-contact-style-${ Koha.Preference( 'AddressFormat' ) }" %]
 [% ELSE %]
 [% PROCESS 'member-alt-contact-style-us' %]
 [% END %]
 </ol>
 </fieldset>
[% END %]

[% BLOCK 'member-alt-contact-style-us' %]
 [% PROCESS 'alt-contact-style_altcontactsurname' %]
 [% PROCESS 'alt-contact-style_altcontactfirstname' %]
 [% PROCESS 'alt-contact-style_altcontactaddress1' %]
 [% PROCESS 'alt-contact-style_altcontactaddress2' %]
 [% PROCESS 'alt-contact-style_altcontactaddress3' %]
 [% PROCESS 'alt-contact-style_altcontactstate' %]
 [% PROCESS 'alt-contact-style_altcontactzipcode' %]
 [% PROCESS 'alt-contact-style_altcontactcountry' %]
 [% PROCESS 'alt-contact-style_altcontactphone' %]
[% END %]

[% BLOCK 'member-alt-contact-style-de' %]
 [% PROCESS 'alt-contact-style_altcontactsurname' %]
 [% PROCESS 'alt-contact-style_altcontactfirstname' %]
 [% PROCESS 'alt-contact-style_altcontactaddress1' %]
 [% PROCESS 'alt-contact-style_altcontactaddress2' %]
 [% PROCESS 'alt-contact-style_altcontactzipcode' %]
 [% PROCESS 'alt-contact-style_altcontactaddress3' %]
 [% PROCESS 'alt-contact-style_altcontactstate' %]
 [% PROCESS 'alt-contact-style_altcontactcountry' %]
 [% PROCESS 'alt-contact-style_altcontactphone' %]
[% END %]

[% BLOCK 'member-alt-contact-style-fr' %]
 [% PROCESS 'alt-contact-style_altcontactsurname' %]
 [% PROCESS 'alt-contact-style_altcontactfirstname' %]
 [% PROCESS 'alt-contact-style_altcontactaddress1' %]
 [% PROCESS 'alt-contact-style_altcontactaddress2' %]
 [% PROCESS 'alt-contact-style_altcontactzipcode' %]
 [% PROCESS 'alt-contact-style_altcontactaddress3' %]
 [% PROCESS 'alt-contact-style_altcontactstate' %]
 [% PROCESS 'alt-contact-style_altcontactcountry' %]
 [% PROCESS 'alt-contact-style_altcontactphone' %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactsurname' %]
 [% UNLESS noaltcontactsurname %]
 <li>
 [% IF ( mandatoryaltcontactsurname ) %]
 <label for="altcontactsurname" class="required">
 [% ELSE %]
 <label for="altcontactsurname">
 [% END %] اللقب: </label>
 <input type="text" name="altcontactsurname" id="altcontactsurname" value="[% patron.altcontactsurname | html %]" />
 [% IF ( mandatoryaltcontactsurname ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactfirstname' %]
 [% UNLESS noaltcontactfirstname %]
 <li>
 [% IF ( mandatoryaltcontactfirstname ) %]
 <label for="altcontactfirstname" class="required">
 [% ELSE %]
 <label for="altcontactfirstname">
 [% END %] الاسم الأول: </label>
 <input type="text" name="altcontactfirstname" id="altcontactfirstname" value="[% patron.altcontactfirstname | html %]" />
 [% IF ( mandatoryaltcontactfirstname ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactaddress1' %]
 [% UNLESS noaltcontactaddress1 %]
 <li>
 [% IF ( mandatoryaltcontactaddress1 ) %]
 <label for="altcontactaddress1" class="required">
 [% ELSE %]
 <label for="altcontactaddress1">
 [% END %] العنوان: </label>
 <input type="text" name="altcontactaddress1" id="altcontactaddress1" value="[% patron.altcontactaddress1 | html %]" size="40" />
 [% IF ( mandatoryaltcontactaddress1 ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactaddress2' %]
 [% UNLESS noaltcontactaddress2 %]
 <li>
 [% IF ( mandatoryaltcontactaddress2 ) %]
 <label for="altcontactaddress2" class="required">
 [% ELSE %]
 <label for="altcontactaddress2">
 [% END %] العنوان 2: </label>
 <input type="text" name="altcontactaddress2" id="altcontactaddress2" value="[% patron.altcontactaddress2 | html %]" size="40" />
 [% IF ( mandatoryaltcontactaddress2 ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactzipcode' %]
 [% UNLESS noaltcontactzipcode %]
 <li>
 [% IF ( mandatoryaltcontactzipcode ) %]
 <label for="altcontactzipcode" class="required">
 [% ELSE %]
 <label for="altcontactzipcode">
 [% END %] الرمز البريدى: </label>
<input type="text" name="altcontactzipcode" id="altcontactzipcode" value="[% patron.altcontactzipcode | html %]" size="5" />
 [% IF ( mandatoryaltcontactzipcode ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactaddress3' %]
 [% UNLESS noaltcontactaddress3 %]
 <li>
 [% IF ( mandatoryaltcontactaddress3 ) %]
 <label for="altcontactaddress3" class="required">
 [% ELSE %]
 <label for="altcontactaddress3">
 [% END %] المدينة: </label>
 [% IF cities.count %]
 <select class="select_city" data-addressfield="altcontact" name="select_city">
 <option value="|||"></option>
 [% FOREACH c IN cities %]
 [% IF c.city_name == patron.altcontactaddress3 && c.city_state == patron.altcontactstate && c.city_zipcode == patron.altcontactzipcode %]
 <option value="[% c.city_zipcode | html %]|[% c.city_name | html %]|[% c.city_state | html %]|[% c.city_country | html %]" selected="selected">
 [% ELSE %]
 <option value="[% c.city_zipcode | html %]|[% c.city_name | html %]|[% c.city_state | html %]|[% c.city_country | html %]">
 [% END %]
 [% c.city_name | html %] [% c.city_state | html %] [% c.city_zipcode | html %]
 </option>
 [% END %]
 </select>
 <span class="hint">أو قم بإدخال</span>
 [% END %]
 <input type="text" name="altcontactaddress3" id="altcontactcity" value="[% patron.altcontactaddress3 | html %]" size="20" />
 [% IF ( mandatoryaltcontactaddress3 ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactstate' %]
 [% UNLESS noaltcontactstate %]
 <li>
 [% IF ( mandatoryaltcontactstate ) %]
 <label for="altcontactstate" class="required">
 [% ELSE %]
 <label for="altcontactstate">
 [% END %] المحافظة: </label>
 <input type="text" name="altcontactstate" id="altcontactstate" value="[% patron.altcontactstate | html %]" size="20" />
 [% IF ( mandatoryaltcontactstate ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactcountry' %]
 [% UNLESS noaltcontactcountry %]
 <li>
 [% IF ( mandatoryaltcontactcountry ) %]
 <label for="altcontactcountry" class="required">
 [% ELSE %]
 <label for="altcontactcountry">
 [% END %] البلد: </label>
 <input type="text" name="altcontactcountry" id="altcontactcountry" value="[% patron.altcontactcountry | html %]" size="20" />
 [% IF ( mandatoryaltcontactcountry ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]

[% BLOCK 'alt-contact-style_altcontactphone' %]
 [% UNLESS noaltcontactphone %]
 <li>
 [% IF ( mandatoryaltcontactphone ) %]
 <label for="altcontactphone" class="required">
 [% ELSE %]
 <label for="altcontactphone">
 [% END %] رقم الهاتف: </label>
 <input type="text" name="altcontactphone" id="altcontactphone" value="[% patron.altcontactphone | html %]" />
 [% IF ( mandatoryaltcontactphone ) %]<span class="required">مطلوب</span>[% END %]
 </li>
 [% END %]
[% END %]
