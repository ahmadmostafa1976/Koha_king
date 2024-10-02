[%- BLOCK subtype_dropdowns -%]
 <select name="limit" class="subtype">
 [% IF ( limits.aud.size ) %]
 <option value="" class="menuheader">أى جمهور</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">أى جمهور</option>
 [% END %]
 [% IF (limits.aud.0 == 'a' ) %]
 <option selected="selected" value="aud:a">مرحلة ما قبل المدرسة</option>
 [% ELSE %]
 <option value="aud:a">مرحلة ما قبل المدرسة</option>
 [% END %]
 [% IF (limits.aud.0 == 'b' ) %]
 <option value="aud:b" selected="selected">رئيسي</option>
 [% ELSE %]
 <option value="aud:b">رئيسي</option>
 [% END %]
 [% IF (limits.aud.0 == 'c' ) %]
 <option value="aud:c" selected="selected">مرحلة ما قبل المراهقة</option>
 [% ELSE %]
 <option value="aud:c">مرحلة ما قبل المراهقة</option>
 [% END %]
 [% IF (limits.aud.0 == 'd' ) %]
 <option value="aud:d" selected="selected">يافع</option>
 [% ELSE %]
 <option value="aud:d">يافع</option>
 [% END %]
 [% IF (limits.aud.0 == 'e' ) %]
 <option value="aud:e" selected="selected">بالغ</option>
 [% ELSE %]
 <option value="aud:e">بالغ</option>
 [% END %]
 [% IF (limits.aud.0 == 'f' ) %]
 <option value="aud:f" selected="selected">متخصص</option>
 [% ELSE %]
 <option value="aud:f">متخصص</option>
 [% END %]
 [% IF (limits.aud.0 == 'g' ) %]
 <option value="aud:g" selected="selected">عام</option>
 [% ELSE %]
 <option value="aud:g">عام</option>
 [% END %]
 [% IF (limits.aud.0 == 'j' ) %]
 <option value="aud:j" selected="selected">ناشئة</option>
 [% ELSE %]
 <option value="aud:j">ناشئة</option>
 [% END %]
 [% limits.delete( 'aud' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.fic.size OR limits.bio.size OR limits.mus.size ) %]
 <option value="" class="menuheader">أى محتوى</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">أى محتوى</option>
 [% END %]
 [% IF (limits.fic.0 == '1' ) %]
 <option value="fic:1" selected="selected" >القصة</option>
 [% ELSE %]
 <option value="fic:1" >القصة</option>
 [% END %]
 [% IF (limits.fic.0 == '0' ) %]
 <option value="fic:0" selected="selected" >غير أدبي</option>
 [% ELSE %]
 <option value="fic:0" >غير أدبي</option>
 [% END %]
 [% IF (limits.bio.0 == 'b' ) %]
 <option value="bio:b" selected="selected" >سيرة ذاتية</option>
 [% ELSE %]
 <option value="bio:b" >سيرة ذاتية</option>
 [% END %]
 [% IF (limits.mus.0 == 'j' ) %]
 <option value="mus:j" selected="selected" >تسجيل موسيقي</option>
 [% ELSE %]
 <option value="mus:j" >تسجيل موسيقي</option>
 [% END %]
 [% IF (limits.mus.0 == 'i' ) %]
 <option value="mus:i" selected="selected" >لا تسجيل موسيقي</option>
 [% ELSE %]
 <option value="mus:i" >لا تسجيل موسيقي</option>
 [% END %]
 [% limits.delete( 'fic' ) %]
 [% limits.delete( 'bio' ) %]
 [% limits.delete( 'mus' ) %]
 </select>

 [% SET lformat = 'l-format' %]
 <select name="limit" class="subtype">
 [% IF ( limits.$lformat.size ) %]
 <option value="" class="menuheader">أى تنسيق</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">أى تنسيق</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ta' ) %]
 <option value="l-format:ta" selected="selected" >طبعة منتظمة</option>
 [% ELSE %]
 <option value="l-format:ta" >طبعة منتظمة</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tb' ) %]
 <option value="l-format:tb" selected="selected" >طبعة ضخمة</option>
 [% ELSE %]
 <option value="l-format:tb" >طبعة ضخمة</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tc or fb' ) %]
 <option value="l-format:tc or fb" selected="selected" >طريقة برايل</option>
 [% ELSE %]
 <option value="l-format:tc or fb" >طريقة برايل</option>
 [% END %]
 <option value="" >-----------</option>
 [% IF (limits.$lformat.0 == 'sd' ) %]
 <option value="l-format:sd" selected="selected" >قرص الصوت</option>
 [% ELSE %]
 <option value="l-format:sd" >قرص الصوت</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ss' ) %]
 <option value="l-format:ss" selected="selected" >تسجيل كاسيت</option>
 [% ELSE %]
 <option value="l-format:ss" >تسجيل كاسيت</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vf' ) %]
 <option value="l-format:vf" selected="selected" >VHS شريط / فيديو كاسيت</option>
 [% ELSE %]
 <option value="l-format:vf" >VHS شريط / فيديو كاسيت</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vd' ) %]
 <option value="l-format:vd" selected="selected" >DVD فيديو /ديسك فيديو</option>
 [% ELSE %]
 <option value="l-format:vd" >DVD فيديو /ديسك فيديو</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'co' ) %]
 <option value="l-format:co" selected="selected" >القرص المضغوط للبرنامج</option>
 [% ELSE %]
 <option value="l-format:co" >القرص المضغوط للبرنامج</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'cr' ) %]
 <option value="l-format:cr" selected="selected" >موقع ويب</option>
 [% ELSE %]
 <option value="l-format:cr" >موقع ويب</option>
 [% END %]
 [% limits.delete( 'l-format' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.ctype.size ) %]
 <option value="" >أنواع إضافية للمحتوى</option>
 [% ELSE %]
 <option value="" selected="selected" >أنواع إضافية للمحتوى</option>
 [% END %]
 [% IF (limits.ctype.0 == 'a' ) %]
 <option value="ctype:a" selected="selected" >مستخلصات / ملخصات</option>
 [% ELSE %]
 <option value="ctype:a" >مستخلصات / ملخصات</option>
 [% END %]
 [% IF (limits.ctype.0 == 'b' ) %]
 <option value="ctype:b" selected="selected" >بيبلوغرافيات</option>
 [% ELSE %]
 <option value="ctype:b" >بيبلوغرافيات</option>
 [% END %]
 [% IF (limits.ctype.0 == 'c' ) %]
 <option value="ctype:c" selected="selected" >الفهارس</option>
 [% ELSE %]
 <option value="ctype:c" >الفهارس</option>
 [% END %]
 [% IF (limits.ctype.0 == 'e' ) %]
 <option value="ctype:e" selected="selected" >الموسوعات </option>
 [% ELSE %]
 <option value="ctype:e" >الموسوعات </option>
 [% END %]
 [% IF (limits.ctype.0 == 'f' ) %]
 <option value="ctype:f" selected="selected" >كتيبات</option>
 [% ELSE %]
 <option value="ctype:f" >كتيبات</option>
 [% END %]
 [% IF (limits.ctype.0 == 'g' ) %]
 <option value="ctype:g" selected="selected" >مقالات قانونية</option>
 [% ELSE %]
 <option value="ctype:g" >مقالات قانونية</option>
 [% END %]
 [% IF (limits.ctype.0 == 'i' ) %]
 <option value="ctype:i" selected="selected" >فهارس</option>
 [% ELSE %]
 <option value="ctype:i" >فهارس</option>
 [% END %]
 [% IF (limits.ctype.0 == 'j' ) %]
 <option value="ctype:j" selected="selected" >وثيقة مسجّلة</option>
 [% ELSE %]
 <option value="ctype:j" >وثيقة مسجّلة</option>
 [% END %]
 [% IF (limits.ctype.0 == 'k' ) %]
 <option value="ctype:k" selected="selected" >ديسكوغرافيا</option>
 [% ELSE %]
 <option value="ctype:k" >ديسكوغرافيا</option>
 [% END %]
 [% IF (limits.ctype.0 == 'l' ) %]
 <option value="ctype:l" selected="selected" >التشريع</option>
 [% ELSE %]
 <option value="ctype:l" >التشريع</option>
 [% END %]
 [% IF (limits.ctype.0 == 'm' ) %]
 <option value="ctype:m" selected="selected" >الإطروحات</option>
 [% ELSE %]
 <option value="ctype:m" >الإطروحات</option>
 [% END %]
 [% IF (limits.ctype.0 == 'n' ) %]
 <option value="ctype:n" selected="selected" >مسوحات</option>
 [% ELSE %]
 <option value="ctype:n" >مسوحات</option>
 [% END %]
 [% IF (limits.ctype.0 == 'o' ) %]
 <option value="ctype:o" selected="selected" >مراجعات</option>
 [% ELSE %]
 <option value="ctype:o" >مراجعات</option>
 [% END %]
 [% IF (limits.ctype.0 == 'p' ) %]
 <option value="ctype:p" selected="selected" >نصوص مبرمجة</option>
 [% ELSE %]
 <option value="ctype:p" >نصوص مبرمجة</option>
 [% END %]
 [% IF (limits.ctype.0 == 'q' ) %]
 <option value="ctype:q" selected="selected" >فيلموغرافيا</option>
 [% ELSE %]
 <option value="ctype:q" >فيلموغرافيا</option>
 [% END %]
 [% IF (limits.ctype.0 == 'r' ) %]
 <option value="ctype:r" selected="selected" >الأدلة</option>
 [% ELSE %]
 <option value="ctype:r" >الأدلة</option>
 [% END %]
 [% IF (limits.ctype.0 == 's' ) %]
 <option value="ctype:s" selected="selected" >إحصائيات</option>
 [% ELSE %]
 <option value="ctype:s" >إحصائيات</option>
 [% END %]
 [% IF (limits.ctype.0 == 't' ) %]
 <option value="ctype:t" selected="selected" >تقارير فنية</option>
 [% ELSE %]
 <option value="ctype:t" >تقارير فنية</option>
 [% END %]
 [% IF (limits.ctype.0 == 'v' ) %]
 <option value="ctype:v" selected="selected" >الوضع القانوني وملاحظات القضية</option>
 [% ELSE %]
 <option value="ctype:v" >الوضع القانوني وملاحظات القضية</option>
 [% END %]
 [% IF (limits.ctype.0 == 'w' ) %]
 <option value="ctype:w" selected="selected" >التقارير القانونية والموجزات</option>
 [% ELSE %]
 <option value="ctype:w" >التقارير القانونية والموجزات</option>
 [% END %]
 [% IF (limits.ctype.0 == 'z' ) %]
 <option value="ctype:z" selected="selected" >المعاهدات </option>
 [% ELSE %]
 <option value="ctype:z" >المعاهدات </option>
 [% END %]
 [% limits.delete( 'ctype' ) %]
 </select>
[%- END -%]
