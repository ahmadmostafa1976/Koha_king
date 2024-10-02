<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE stylesheet>
<xsl:stylesheet
 xmlns:marc="http://www.loc.gov/MARC21/slim"
 xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
 xmlns:dc="http://purl.org/dc/elements/1.1/"
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 version="1.0"
 exclude-result-prefixes="marc">
 <xsl:import href="UNIMARCslimUtils.xsl"/>
 <xsl:output method="xml" indent="yes" encoding="UTF-8"/>
 <xsl:template match="/">
 <xsl:apply-templates/>
 </xsl:template>
 <xsl:template match="marc:record">
 <rdf:Description>
 <xsl:for-each select="marc:datafield[@tag=200]">
 <dc:title>
 <xsl:variable name="title" select="marc:subfield[@code='a']"/>
 <xsl:variable name="ntitle"
           select="translate($title, '&#x0098;&#x009C;&#xC29C;&#xC29B;&#xC298;&#xC288;&#xC289;','')"/>
 <xsl:value-of select="$ntitle" />
 <xsl:if test="marc:subfield[@code='e']">
 <xsl:text> : </xsl:text>
 <xsl:for-each select="marc:subfield[@code='e']">
 <xsl:value-of select="."/>
 </xsl:for-each>
 </xsl:if>
 <xsl:for-each select="marc:subfield[@code='h' or @code='i' or @code='v']">
 <xsl:text>, </xsl:text>
 <xsl:value-of select="."/>
 </xsl:for-each>
 </dc:title>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=700 or @tag=701 or @tag=702 or @tag=710 or @tag=711 or @tag=712]">
 <dc:creator>
 <xsl:for-each select="marc:subfield[@code='a' or @code='b' or @code='c' or @code='d']">
 <xsl:value-of select="." />
 <xsl:if test="not(position()=last())">
 <xsl:text>, </xsl:text>
 </xsl:if>
 </xsl:for-each>
 <xsl:choose>
 <xsl:when test="marc:subfield[@code='4']='010'">، محول</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='020'">، مفسر الشروح</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='075'">، مؤلف الكلمة الختامية</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='080'">، مؤلف الافتتاحية</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='100'">، سابقة ببليوغرافية</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='205'">، مشارك</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='212'">، معلق</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='220'">، مصرف</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='230'">، ملحن</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='245'">، كاتب المفهوم</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='295'">، مانح الدرجة</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='340'">، محرر</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='370'">، مونتاج الفيلم</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='395'">، مؤسس</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='440'">، رسام توضيحي</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='520'">، شاعر غنائي</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='557'">، منظم الاجتماعات</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='570'">،أخرى</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='600'">، مصور فوتوغرافي</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='605'">، مقدم</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='650'">، الناشر</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='651'">، مدير النشر</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='673'">، رئيس فريق البحث</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='675'">، مراجع</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='710'">، المحرر</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='723'">، راعي</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='727'">، مستشار الأطروحة</xsl:when>
 <xsl:when test="marc:subfield[@code='4']='730'">، مترجم</xsl:when>
 </xsl:choose>
 </dc:creator>
 </xsl:for-each>
 <dc:type>
 <xsl:value-of select="marc:datafield[@tag=200]/marc:subfield[@code='b']"/>
 </dc:type>
 <xsl:for-each select="marc:datafield[@tag=210]">
 <dc:publisher>
 <xsl:for-each select="marc:subfield[@code='c']">
 <xsl:value-of select="."/>
 <xsl:if test="not(position()=last())">, </xsl:if>
 </xsl:for-each>
 <xsl:if test="marc:subfield[@code='a']">
 <xsl:text> / </xsl:text>
 <xsl:for-each select="marc:subfield[@code='a']">
 <xsl:value-of select="."/>
 <xsl:if test="not(position()=last())">, </xsl:if>
 </xsl:for-each>
 </xsl:if>
 </dc:publisher>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=210]/marc:subfield[@code='d']">
 <dc:date>
 <xsl:value-of select="."/>
 </dc:date>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=101]">
 <xsl:for-each select="marc:subfield[@code='a']">
 <dc:language>
 <xsl:value-of select="."/>
 </dc:language>
 </xsl:for-each>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=856]/marc:subfield[@code='q']">
 <dc:format>
 <xsl:value-of select="."/>
 </dc:format>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[300&lt;@tag][@tag&lt;=337]">
 <dc:description>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:description>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[600&lt;=@tag][@tag&lt;=610]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=461 or @tag=464]">
 <dc:relation>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">t</xsl:with-param>
 </xsl:call-template>
 </dc:relation>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=856]">
 <dc:identifier>
 <xsl:value-of select="marc:subfield[@code='u']"/>
 </dc:identifier>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=010]">
 <dc:identifier>
 <xsl:text>URN:ISBN:</xsl:text>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:identifier>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=011]">
 <dc:identifier>
 <xsl:text>URN:ISSN:</xsl:text>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:identifier>
 </xsl:for-each>
 <xsl:for-each select="marc:datafield[@tag=995]">
 <dc:identifier>
 <xsl:text>LOC:</xsl:text>
 <xsl:for-each select="marc:subfield[@code='k']">
 <xsl:text>:</xsl:text>
 <xsl:value-of select="."/>
 </xsl:for-each>
 </dc:identifier>
 </xsl:for-each>
 </rdf:Description>
 </xsl:template>
</xsl:stylesheet>
