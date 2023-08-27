<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<!--xsl:stylesheet> определяет, что данный документ является таблицей
 стилей XSLT с атрибутами номера версии и пространства имен XSLT.-->
<xsl:template match="body">
<!--
    Значение «/» атрибут match используется, чтобы определить шаблон для всего XML
     документа целиком.
-->
    <html>
    <head>
        <title>Оценки</title>
    </head>
    <body>
    <table border="1">
        <tr bgcolor="skyblue">
            <th>Имя</th>
            <th>КЯР</th>
            <th>Math</th>
            <th>Math2</th>
            <th>ОАиП</th>
        </tr>
        <xsl:for-each select="people">
        <!--
        <xsl:sort> используется для сортировки выходных данных b
        располагается внутри элемента <xsl:for-each>

        <xsl:for-each> может использоваться для выбора каждого XML элемента
         заданного узлового набора
        -->
        <tr>
            <td><xsl:value-of select="name"/></td>
            <!-- <xsl:value-of> используется для извлечения значения отобранного
            XML элемента и добавления его в выходной поток преобразовываемого
            документа.-->

            <xsl:choose>
            <!-- <xsl:choose> используется вместе с элементами <xsl:when>
             и <xsl:otherwise>, чтобы определить проверку на выполнение условия(Сортировка с условием)-->
                <xsl:when test="rating1 &gt; 8">
                    <td bgcolor="green"><xsl:value-of select="rating1"/></td>
                </xsl:when>

                <xsl:when test="rating1 &lt; 4">
                    <td bgcolor="red"><xsl:value-of select="rating1"/></td>
                </xsl:when>

                <xsl:otherwise>
                    <td><xsl:value-of select="rating1"/></td>
                </xsl:otherwise>
              </xsl:choose>

            <xsl:choose>

                <xsl:when test="rating2 &gt; 8">
                    <td bgcolor="green"><xsl:value-of select="rating2"/></td>
                </xsl:when>

                <xsl:when test="rating2 &lt; 4">
                    <td bgcolor="red"><xsl:value-of select="rating2"/></td>
                </xsl:when>

                <xsl:otherwise>
                    <td><xsl:value-of select="rating2"/></td>
                </xsl:otherwise>

            </xsl:choose>
            <xsl:choose>

                <xsl:when test="rating3 &gt; 8">
                  <td bgcolor="green"><xsl:value-of select="rating3"/></td>
                </xsl:when>

                <xsl:when test="rating3 &lt; 4">
                    <td bgcolor="red"><xsl:value-of select="rating3"/></td>
                </xsl:when>

                <xsl:otherwise>
                    <td><xsl:value-of select="rating3"/></td>
                </xsl:otherwise>

            </xsl:choose>

            <xsl:choose>

                <xsl:when test="rating4 &gt; 8">
                    <td bgcolor="green"><xsl:value-of select="rating4"/></td>
                </xsl:when>

                <xsl:when test="rating4 &lt; 4">
                    <td bgcolor="red"><xsl:value-of select="rating4"/></td>
                </xsl:when>

                <xsl:otherwise>
                    <td><xsl:value-of select="rating4"/></td>
                </xsl:otherwise>

            </xsl:choose>
        </tr>

        </xsl:for-each>
    </table>
    </body>
    </html>
</xsl:template>
</xsl:stylesheet>
<!--XSLT (eXtensible Stylesheet Language Transformations) — это

<> декларативное описание преобразования (трансформации) любого XMLдокумента.-->
<!--<xsl:apply-templates> применяет некий шаблон к текущему элементу
или к дочернему узлу текущего элемента. Если в элемент <xsl:applytemplates>
 добавить атрибут select, то он будет относиться только к
дочернему элементу, который соответствует значению этого атрибута и может
использоваться для определения порядка, в котором будут обрабатываться
дочерние узлы.-->
