<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="body">
 <html>
<head><title>My first template rule</title>
</head>
 <body>
 <h2>INFO</h2>
 <table border="1">
   <tr bgcolor="#9acd32">
     <th>First name</th>
     <th>Last name</th>
     <th>Age</th>
     <th>Country</th>
     <th>Location</th>
     <th>Native city</th>
   </tr>

   <xsl:for-each select="PERSON">
     <xsl:sort select="FIRST_NAME"/>
     <tr>
       <td><xsl:value-of select="FIRST_NAME"/></td>
       <td><xsl:value-of select="LAST_NAME"/></td>
       <td><xsl:value-of select="AGE"/></td>
       <td><xsl:value-of select="COUNTRY"/></td>
       <td><xsl:value-of select="LOCATION"/></td>
       <td><xsl:value-of select="NATIVE_CITY"/></td>
     </tr>
    </xsl:for-each>

 </table>
 </body>
 </html>
</xsl:template>
</xsl:stylesheet>
