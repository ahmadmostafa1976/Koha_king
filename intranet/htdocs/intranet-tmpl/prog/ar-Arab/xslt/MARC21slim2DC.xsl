<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE stylesheet>
<!-- $Id: MARC21slim2DC.xsl,v 1.1 2003/01/06 08:20:27 adam Exp $ -->
<xsl:stylesheet version="1.0"
  xmlns:marc="http://www.loc.gov/MARC21/slim"
  xmlns:dc="http://purl.org/dc/elements/1.1/"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  exclude-result-prefixes="marc">
 <xsl:import href="MARC21slimUtils.xsl"/>
 <xsl:output method="xml" indent="yes" encoding="UTF-8"/>
 
 <xsl:template match="/">
 <xsl:apply-templates/>
 </xsl:template>

 <xsl:template match="marc:record">
 <xsl:variable name="leader" select="marc:leader"/>
 <xsl:variable name="leader6" select="substring($leader,7,1)"/>
 <xsl:variable name="leader7" select="substring($leader,8,1)"/>
 <xsl:variable name="controlField008" select="marc:controlfield[@tag=008]"/>

 <dc:dc>
 <xsl:for-each select="marc:datafield[@tag=245]">
 <dc:title>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abfghk</xsl:with-param>
 </xsl:call-template>
 </dc:title>
 </xsl:for-each>

 
 <xsl:for-each select="marc:datafield[@tag=100]|marc:datafield[@tag=110]|marc:datafield[@tag=111]|marc:datafield[@tag=700]|marc:datafield[@tag=710]|marc:datafield[@tag=711]|marc:datafield[@tag=720]">
 <dc:creator>
 <xsl:value-of select="."/>
 </dc:creator>
 </xsl:for-each>

 <dc:type> 
 <xsl:if test="$leader7='c'">
 <xsl:attribute name="collection">نعم</xsl:attribute>
 </xsl:if>

 <xsl:if test="$leader6='d' or $leader6='f' or $leader6='p' or $leader6='t'">
 <xsl:attribute name="manuscript">نعم</xsl:attribute>
 </xsl:if>

 <xsl:choose>
 <xsl:when test="$leader6='a' or $leader6='t'">نص</xsl:when>
 <xsl:when test="$leader6='e' or $leader6='f'">رسم الخرائط</xsl:when>
 <xsl:when test="$leader6='c' or $leader6='d'">نوتة موسيقية</xsl:when>
 <xsl:when test="$leader6='i' or $leader6='j'">تسجيل الصوت</xsl:when>
 <xsl:when test="$leader6='k'">صورة ثابتة</xsl:when>
 <xsl:when test="$leader6='g'">تحريك صورة</xsl:when>
 <xsl:when test="$leader6='r'">كائن ثلاثي الأبعاد</xsl:when>
 <xsl:when test="$leader6='m'">البرمجيات, الوسائط المتعددة</xsl:when>
 <xsl:when test="$leader6='p'">مادة مختلطة</xsl:when>
 </xsl:choose>
 </dc:type>

 <xsl:for-each select="marc:datafield[@tag=655]">
 <dc:type>
 <xsl:value-of select="."/>
 </dc:type>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=260]">
 <dc:publisher>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">ab</xsl:with-param>
 </xsl:call-template>
 </dc:publisher>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=260]/marc:subfield[@code='c']">
 <dc:date>
 <xsl:value-of select="."/>
 </dc:date> 
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=264]">
 <dc:publisher>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">ab</xsl:with-param>
 </xsl:call-template>
 </dc:publisher>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=264]/marc:subfield[@code='c']">
 <dc:date>
 <xsl:value-of select="."/>
 </dc:date>
 </xsl:for-each>

 <dc:language>
 <xsl:value-of select="substring($controlField008,36,3)"/>
 </dc:language>

 <xsl:for-each select="marc:datafield[@tag=856]/marc:subfield[@code='q']">
 <dc:format>
 <xsl:value-of select="."/>
 </dc:format>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=520]">
 <dc:description>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:description>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=521]">
 <dc:description>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:description>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[500&lt;@tag][@tag&lt;=599][not(@tag=506 or @tag=530 or @tag=540 or @tag=546)]">
 <dc:description>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:description>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=600]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=610]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=611]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>
 
 <xsl:for-each select="marc:datafield[@tag=630]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=650]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=653]">
 <dc:subject>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdq</xsl:with-param>
 </xsl:call-template>
 </dc:subject>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=752]">
 <dc:coverage>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcd</xsl:with-param>
 </xsl:call-template>
 </dc:coverage>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=530]">
 <dc:relation type="original">
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">abcdu</xsl:with-param>
 </xsl:call-template>
 </dc:relation> 
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=760]|marc:datafield[@tag=762]|marc:datafield[@tag=765]|marc:datafield[@tag=767]|marc:datafield[@tag=770]|marc:datafield[@tag=772]|marc:datafield[@tag=773]|marc:datafield[@tag=774]|marc:datafield[@tag=775]|marc:datafield[@tag=776]|marc:datafield[@tag=777]|marc:datafield[@tag=780]|marc:datafield[@tag=785]|marc:datafield[@tag=786]|marc:datafield[@tag=787]">
 <dc:relation>
 <xsl:call-template name="subfieldSelect">
 <xsl:with-param name="codes">ot</xsl:with-param>
 </xsl:call-template>
 </dc:relation> 
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=856]">
 <dc:identifier>
 <xsl:value-of select="marc:subfield[@code='u']"/>
 </dc:identifier>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=506]">
 <dc:rights>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:rights>
 </xsl:for-each>

 <xsl:for-each select="marc:datafield[@tag=540]">
 <dc:rights>
 <xsl:value-of select="marc:subfield[@code='a']"/>
 </dc:rights>
 </xsl:for-each>
 </dc:dc>
 </xsl:template>
</xsl:stylesheet>
