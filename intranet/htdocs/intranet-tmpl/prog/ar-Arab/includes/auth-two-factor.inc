[% BLOCK registration_form %]
 <div id="registration-form" style="display: none;">
 <div class="dialog message">
 <p>نوصي بتطبيقات الاستيثاق للهاتف المستندة إلى السحابة مثل Authy و Duo Mobile و LastPass. حيث يمكنها استعادة الوصول إذا فقدت جهازك.</p>
 <p>لا يمكنك مسح الرمز ضوئياً؟</p>
 <p>لإضافة الإدخال يدويًا، قم بتوفير التفاصيل التالية للتطبيق الموجود على هاتفك.</p>
 <p>الحساب: "<span id="issuer">[% issuer | html %]</span>: <span id="key_id">[% key_id | html %]</span>"</p>
 <p>المفتاح: "<span id="key_secret">[% secret32 | html %]</span>"</p>
 <p>على أساس الوقت: نعم</p>
 </div>

 <div id="errors" class="dialog error" style="display: none;"></div>

 <fieldset class="rows">
 <input type="hidden" id="secret32" name="secret32" value="[% secret32 | html %]" />
 <ol>
 <li>
 <label for="qr_code">رمز الاستجابة السريعة: </label>
 <img id="qr_code" src="" />
 </li>
 <li>
 <label for="pin_code">رمز التعريف الشخصي: </label>
 <input type="text" id="pin_code" name="pin_code" value="" />
 </li>
 </ol>
 </fieldset>
 <fieldset class="action">
 <input id="register-2FA" type="submit" value="تسجيل في تطبيق ثنائي الاستيثاق" />
 <a class="cancel" href="/cgi-bin/koha/members/two_factor_auth.pl">إلغاء</a>
 </fieldset>
 </div>
[% END %]
