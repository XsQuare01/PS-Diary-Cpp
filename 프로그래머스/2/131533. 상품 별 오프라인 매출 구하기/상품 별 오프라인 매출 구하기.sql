-- 코드를 입력하세요
SELECT PRODUCT.PRODUCT_CODE, SUM(PRODUCT.PRICE * SALES_AMOUNT) AS SALES
FROM PRODUCT JOIN OFFLINE_SALE USING(PRODUCT_ID)
GROUP BY OFFLINE_SALE.PRODUCT_ID
ORDER BY SALES DESC, PRODUCT.PRODUCT_CODE;