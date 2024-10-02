[%- BLOCK role -%]
 [% matches = role.key.match('(\w+):?(.*)?') %]
 [% ro = matches.0 %]
 [% ex = matches.1 %]
 [%- SWITCH ro -%]
 [%- CASE 'manager'               -%]<span>مدير الإصدار</span>
 [%- CASE 'manager_assistant'     -%]<span>مساعد مدير الإصدار</span>
 [%- CASE 'manager_mentor'        -%]<span>مشرف مدير الإصدار</span>
 [%- CASE 'qa_manager'            -%]<span>مدير ضمان الجودة</span>
 [%- CASE 'qa'                    -%]<span>فريق ضمان الجودة</span>
 [%- CASE 'documentation'         -%]<span>مدير التوثيق</span>
 [%- CASE 'documentation_team'    -%]<span>فريق التوثيق</span>
 [%- CASE 'translation'           -%]<span>مدير الترجمة</span>
 [%- CASE 'translations'          -%]<span>مديري الترجمة</span>
 [%- CASE 'translation_assistant' -%]<span>مساعد مدير الترجمة</span>
 [%- CASE 'te'                    -%]<span>خبير الموضوع</span>
 [%- CASE 'bugwrangler'           -%]<span>مكافح الخلل</span>
 [%- CASE 'maintainer'            -%]<span>مسؤول صيانة الإصدار</span>
 [%- CASE 'maintainer_assistant'  -%]<span>مساعد مسؤول صيانة الإصدار</span>
 [%- CASE 'maintainer_mentor'     -%]<span>مشرف مسؤول صيانة الإصدار</span>
 [%- CASE 'wiki'                  -%]<span>أمين الويكي</span>
 [%- CASE 'ci'                    -%]<span>مدير التكامل المستمر</span>
 [%- CASE 'packaging'             -%]<span>مدير الحزم</span>
 [%- CASE 'packaging_assistant'   -%]<span>مساعد مدير الحزم</span>
 [%- CASE 'chairperson'           -%]<span>رئيس الاجتماعات</span>
 [%- CASE 'newsletter'            -%]<span>محرر نشرة الأخبار</span>
 [%- CASE 'mm'                    -%]<span>مسؤول صيانة النظام الفرعي</span>
 [%- CASE 'vm'                    -%]<span>مسؤول صيانة الآلة الافتراضية</span>
 [%- CASE 'database'              -%]<span>أخصائي التوثيق</span>
 [%- CASE 'live_cd'               -%]<span>مسئول صيانة Live CD</span>
 [%- CASE 'accessibility_advocate'-%]<span>مسؤول الوصول</span>
 [%- CASE 'meeting_facilitator'   -%]<span>ميسر الاجتماع</span>
 [%- CASE 'ktd'                   -%]<span>أدوات المطور</span>
 [%- CASE 'website'               -%]<span>مسؤول الموقع الإلكتروني</span>
 [%- CASE -%]<span>خريطة مفقودة للدور: [% role.key | html %]</span>
 [%- END -%]
 [%- IF ex %] - [% ex | html %][% END -%]
[%- END -%]

[%- BLOCK person -%]
[% IF p.openhub %]<a href="[% p.openhub | url %]">[% p.name | html %]</a>[% ELSE %][% p.name | html %][% END %]
[%- END -%]

[%- BLOCK contributions -%]
[%- IF p.roles || p.notes -%]
<ul>
 [% FOREACH r IN p.roles %]<li>[% INCLUDE role role=r %] ([% r.value.join(', ') | html %])</li>[% END %]
 [% IF p.notes %]<li>[% p.notes | html %]</li>[% END %]
</ul>
[%- END -%]
[%- END -%]

[%- BLOCK team -%]
 <ul>

 [% IF v == 'release' %]
 <p>هذا هو الفريق المسؤول عن الإصدار المبدئي لإصدار كوها الحالي.</p>

 <li><strong>مدير الإصدار:</strong>
 [% INCLUDE person p=t.manager %]
 </li>

 [% IF t.manager_assistants %]
 <li><strong>مساعد مدير الإصدار:</strong>
 <ul>
 [% FOREACH a IN t.manager_assistants %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.manager_assistant %]
 <li><strong>مساعد مدير الإصدار:</strong>
 [% INCLUDE person p=t.manager_assistant %]
 </li>
 [% END %]

 [% ELSE %]
 <p>هذا هو الفريق المسؤول عن الإصدار التالي من كوها والصيانة القائمة لإصدار كوها الحالي. وسيتولى هذه المسؤولية حتى <strong>[% t.release_date | $KohaDates %]</strong>، عندما يتم انتخاب الفريق التالي.</p>

 [% FOREACH m IN t.maintainer %]
 [% IF m.version == ( v ) %]
 <li><strong>مسؤول صيانة الإصدار:</strong>
 [% INCLUDE person p=m %]
 </li>
 [% END %]
 [% END %]
 
 [% IF t.maintainer_assistants %]
 [% FOREACH m IN t.maintainer_assistants %]
 [% IF m.version == ( v ) %]
 <ul><li><strong>مساعد:</strong> [% INCLUDE person p=m %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 
 [% IF t.maintainer_mentors %]
 [% FOREACH m IN t.maintainer_mentors %]
 [% IF m.version == ( v ) %]
 <ul><li><strong>معلم:</strong> [% INCLUDE person p=m %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 [% END %]

 [% IF t.qa_manager %]
 <li><strong>مدير ضمان الجودة:</strong>
 [% INCLUDE person p=t.qa_manager %]
 </li>
 [% END %]

 [% IF t.qa %]
 <li><strong>فريق ضمان الجودة:</strong>
 <ul>
 [% FOREACH qa IN t.qa %]
 <li>[% INCLUDE person p=qa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.documentation %]
 [%- IF t.documentation.list.size == 1 %]
 <li><strong>مدير التوثيق:</strong>
 [% INCLUDE person p=t.documentation %]
 </li>
 [% ELSE %]
 <li><strong>مديري التوثيق:</strong>
 <ul>
 [% FOREACH doc_manager IN t.documentation %]
 <li>[% INCLUDE person p=doc_manager %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.documentation_team %]
 <li><strong>فريق التوثيق:</strong>
 <ul>
 [% FOREACH doc_member IN t.documentation_team %]
 <li>[% INCLUDE person p=doc_member %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.translation %]
 <li><strong>مدير الترجمة:</strong>
 [% INCLUDE person p=t.translation %]
 </li>
 [% END %]

 [% IF t.translations %]
 <li><strong>مديري الترجمة:</strong>
 <ul>
 [% FOREACH translation_manager IN t.translations %]
 <li>[% INCLUDE person p=translation_manager %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.packaging %]
 [% IF t.packaging.size / 2 == 1 %]
 <li><strong>مدير الحزم:</strong>
 [% INCLUDE person p=t.packaging %]
 </li>
 [% ELSE %]
 <li><strong>فريق الحزم:</strong>
 <ul>
 [% FOREACH pa IN t.packaging %]
 <li>[% INCLUDE person p = pa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.packaging_assistant %]
 [% IF t.packaging_assistant.size / 2 == 1 %]
 <li><strong>مساعد مدير الحزم:</strong>
 [% INCLUDE person p=t.packaging_assistant %]
 </li>
 [% ELSE %]
 <li><strong>مساعدي مدير الحزم:</strong>
 <ul>
 [% FOREACH pa IN t.packaging_assistant %]
 <li>[% INCLUDE person p = pa %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.ci %]
 [% IF t.ci.size == 1 %]
 <li><strong>مسؤول التكامل المستمر:</strong>
 [% INCLUDE person p=t.ci.0 %]
 </li>
 [% ELSE %]
 <li><strong>مسؤولي التكامل المستمر:</strong>
 <ul>
 [% FOREACH j IN t.ci %]
 <li>[% INCLUDE person p=j %]
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.ktd %]
 [% IF t.ktd.size == 1 %]
 <li><strong><a href="https://gitlab.com/koha-community/koha-testing-docker">KTD</a> مسؤول الصيانة:</strong>
 [% INCLUDE person p=t.ktd.0 %]
 </li>
 [% ELSE %]
 <li><strong><a href="https://gitlab.com/koha-community/koha-testing-docker">KTD</a> مسؤولي الصيانة:</strong>
 <ul>
 [% FOREACH j IN t.ktd %]
 <li>[% INCLUDE person p=j %]
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF t.bugwrangler %]
 <li><strong>مكافح الخلل:</strong>
 <ul>
 [% FOREACH bugwrangler IN t.bugwrangler %]
 <li>[% INCLUDE person p=bugwrangler %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]

 [% IF t.accessibility_advocates %]
 <li><strong>مسؤولي الوصول:</strong>
 <ul>
 [% FOREACH a IN t.accessibility_advocates %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.accessibility_advocate %]
 <li><strong>مسؤول الوصول:</strong>
 [% INCLUDE person p=t.accessibility_advocate %]
 </li>
 [% END %]

 [% IF t.newsletter %]
 <li><strong>محرر نشرة الأخبار:</strong>
 [% INCLUDE person p=t.newsletter %]
 </li>
 [% END %]

 [% IF t.website %]
 <li><strong>مسؤول صيانة الموقع الإلكتروني:</strong>
 [% INCLUDE person p=t.website %]
 </li>
 [% END %]

 [% IF t.wiki %]
 [% IF t.wiki.size == 1 %]
 <li><strong>مدير الويكي:</strong>
 [% INCLUDE person p=t.wiki %]
 </li>
 [% ELSE %]
 <li><strong>فريق الويكي:</strong>
 <ul>
 [% FOREACH wi IN t.wiki %]
 <li>[% INCLUDE person p = wi %]</li>
 [% END %]
 </ul>
 </li>
 [% END %]
 [% END %]

 [% IF v != 'release' %]

 <li><strong>مدير الإصدار:</strong>
 [% INCLUDE person p=t.manager %]
 </li>

 [% IF t.manager_assistants %]
 <li><strong>مساعد مدير الإصدار:</strong>
 <ul>
 [% FOREACH a IN t.manager_assistants %]
 <li>[% INCLUDE person p=a %]</li>
 [% END %]
 </ul>
 </li>
 [% ELSIF t.manager_assistant %]
 <li><strong>مساعد مدير الإصدار:</strong>
 [% INCLUDE person p=t.manager_assistant %]
 </li>
 [% END %]

 [% ELSE %]
 <li><strong>مسئولي صيانة الإصدار:</strong>
 <ul>
 [% FOREACH m IN t.maintainer %]
 <li>[% m.version | html %] - [% INCLUDE person p=m %]</li>
 [% IF t.maintainer_assistants %]
 [% FOREACH ma IN t.maintainer_assistants %]
 [% IF ma.version == ( m.version ) %]
 <ul><li><strong>مساعد:</strong> [% INCLUDE person p=ma %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 
 [% IF t.maintainer_mentors %]
 [% FOREACH mm IN t.maintainer_mentors %]
 [% IF m.version == ( mm.version ) %]
 <ul><li><strong>معلم:</strong> [% INCLUDE person p=mm %]</li></ul>
 [% END %]
 [% END %]
 [% END %]
 [% END %]
 </ul>
 </li>
 [% END %]
 </ul>
[%- END -%]
