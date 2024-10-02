[% IF blocking_error %]
 [% SWITCH blocking_error %]
 [% CASE 'unknown_patron' %]
 <div class="dialog message">لم يتم العثور على المستفيد. <a href="/cgi-bin/koha/members/members-home.pl">العودة إلى البحث</a></div>
 [% CASE 'cannot_see_patron_infos' %] لا يمكن لهذا الحساب مشاهدة معلومات المستفيد المطلوبة. [% CASE 'unknown_biblio' %] <div class="dialog message">لم يتم العثور على التسجيلة الببليوغرافية.</div>
 [% CASE 'unknown_item' %]
 <div class="dialog message">لم يتم العثور على المادة.</div>
 [% CASE 'unknown_subscription' %]
 <div class="dialog message">لم يتم العثور على الاشتراك.</div>
 [% CASE 'unknown_basket' %]
 <div class="dialog message">لم يتم العثور على السلة.</div>
 [% CASE 'unknown_vendor' %]
 <div class="dialog message">لم يتم العثور على المزود.</div>
 [% CASE 'unknown_ill_request' %]
 <div class="dialog message">لم يتم العثور على طلب الإعارة البينية.</div>
 [% CASE 'order_cannot_be_edited' %]
 <div class="dialog message">لا يمكن تعديل هذه الطلبية، قد تكون السلة مغلقة أو تم استلام الطلبية بالفعل.</div>
 [% CASE 'wrong_csrf_token' %]
 <div class="dialog alert">فشل تقديم النموذج (رمز CSRF خاطئ). حاول العودة مرة أخرى، تحديث الصفحة ثم إعادة المحاولة.</div>
 [% CASE 'budget_is_locked' %]
 <div class="dialog message">الميزانية مقفلة، لا يمكن إنشاء التمويل.</div>
 [% CASE 'missing_es_modules' %]
 <div class="dialog message">لم يتم تثبيت حزم Elasticsearch ضرورية في خادمك. يرجى الاتصال بمدير الخادم إذا كنت ترغب في تهيئة Elasticsearch</div>
 [% CASE 'insufficient_permission' %]
 <div class="dialog message">ليس لديك صلاحيات كافية للمتابعة.</div>
 [% CASE %]
 <div class="dialog alert">[% blocking_error | html %]</div>
 [% END %]

 [% INCLUDE 'intranet-bottom.inc' %]
 [% STOP %] [%# Will stop gracefully without processing any more of the template document.%]
[% END %]
