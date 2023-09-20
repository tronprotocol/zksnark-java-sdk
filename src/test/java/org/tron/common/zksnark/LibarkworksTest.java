package org.tron.common.zksnark;

import com.sun.org.apache.xerces.internal.impl.dv.util.HexBin;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.math.BigInteger;
import java.util.Arrays;

import org.junit.Test;

public class LibarkworksTest {
    @Test
    public void libarkworksG1IsValid() {
        byte[] g1 = new byte[64];
        byte[][] g1XY = getG1XY(g1);
        boolean isValid = LibarkworksWrapper.getInstance().libarkworksG1IsValid(g1XY[0], g1XY[1]);
        assertTrue("G1 point (0, 0) should be valid", isValid);

        // this case is valid with the java implementation of BN254
        isValid = LibarkworksWrapper.getInstance().libarkworksG1IsValid(new byte[0], new byte[0]);
        assertTrue("G1 point (0, 0) should be valid", isValid);

        LibarkworksWrapper.getInstance().libarkworksRandomG1(g1);
        g1XY = getG1XY(g1);
        isValid = LibarkworksWrapper.getInstance().libarkworksG1IsValid(g1XY[0], g1XY[1]);
        assertTrue("Random G1 point should be valid", isValid);

        byte[] x = decimalStringToBytes("1284141008968177401446123273711643349693445534482996744734158642473403649434");
        byte[] y = decimalStringToBytes("6652232392179121025009765525095111191899542355288332634641296965917801744215");
        isValid = LibarkworksWrapper.getInstance().libarkworksG1IsValid(x, y);
        assertTrue("G1 point should be valid", isValid);

        x = decimalStringToBytes("1284141008968177401446123273711643349693445534482996744734158642473403649435");
        y = decimalStringToBytes("6652232392179121025009765525095111191899542355288332634641296965917801744215");
        isValid = LibarkworksWrapper.getInstance().libarkworksG1IsValid(x, y);
        assertFalse("G1 point should NOT be valid", isValid);
    }

    @Test
    public void libarkworksG2IsValid() {
        byte[] g2 = new byte[128];
        byte[][] g2ABCD = getG2ABCD(g2);
        boolean isValid = LibarkworksWrapper.getInstance().libarkworksG2IsValid(g2ABCD[0], g2ABCD[1], g2ABCD[2], g2ABCD[3]);
        assertTrue("G2 point (0, 0, 0, 0) should be valid", isValid);

        // this case is valid with the java implementation of BN254
        isValid = LibarkworksWrapper.getInstance().libarkworksG2IsValid(new byte[0], new byte[0], new byte[0],
                new byte[0]);
        assertTrue("G2 point (0, 0, 0, 0) should be valid", isValid);

        LibarkworksWrapper.getInstance().libarkworksRandomG2(g2);
        g2ABCD = getG2ABCD(g2);
        isValid = LibarkworksWrapper.getInstance().libarkworksG2IsValid(g2ABCD[0], g2ABCD[1], g2ABCD[2], g2ABCD[3]);
        assertTrue("Random G2 point should be valid", isValid);

        byte[] a = decimalStringToBytes("21121751982565218239254353368172068966841985326481744739199573873176012212444");
        byte[] b = decimalStringToBytes("10714328940565706835656507512525563808003404883416989196062222412736825474535");
        byte[] c = decimalStringToBytes("6032274688546681517580073545556919091181545541514426001760248014080068448729");
        byte[] d = decimalStringToBytes("3861041822235706362318471606688154602339352702913131403223701683401789305194");
        isValid = LibarkworksWrapper.getInstance().libarkworksG2IsValid(a, b, c, d);
        assertTrue("G2 point should be valid", isValid);

        a = decimalStringToBytes("21121751982565218239254353368172068966841985326481744739199573873176012212445");
        b = decimalStringToBytes("10714328940565706835656507512525563808003404883416989196062222412736825474535");
        c = decimalStringToBytes("6032274688546681517580073545556919091181545541514426001760248014080068448729");
        d = decimalStringToBytes("3861041822235706362318471606688154602339352702913131403223701683401789305194");
        isValid = LibarkworksWrapper.getInstance().libarkworksG2IsValid(a, b, c, d);
        assertFalse("G2 point should NOT be valid", isValid);
    }

    @Test
    public void libarkworksAddG1() {
        byte[] x1 = decimalStringToBytes("1284141008968177401446123273711643349693445534482996744734158642473403649434");
        byte[] y1 = decimalStringToBytes("6652232392179121025009765525095111191899542355288332634641296965917801744215");
        byte[] p1 = concat(x1, y1);

        byte[] x2 = decimalStringToBytes("1138727310856149830881699283295531549904445644547980102009978040558245602177");
        byte[] y2 = decimalStringToBytes("17007876717863907135144187607286180690188030689394587325056604331322830212672");
        byte[] p2 = concat(x2, y2);

        byte[] x3 = decimalStringToBytes("20102382515752348416946264354484414766888026124153337256604214638968111116366");
        byte[] y3 = decimalStringToBytes("17677679321201222010634958653214725343119435180121348086429362586364864643842");
        byte[] p3 = concat(x3, y3);

        byte[] infinity = new byte[64];

        byte[] result = new byte[64];
        boolean success = LibarkworksWrapper.getInstance().libarkworksAddG1(p1, p2, result);
        assertTrue("Addition should be successful", success);
        assertTrue("Actual result is not equal to expected", Arrays.equals(p3, result));

        success = LibarkworksWrapper.getInstance().libarkworksAddG1(p1, infinity, result);
        assertTrue("Addition should be successful", success);
        assertTrue("Actual result is not equal to expected", Arrays.equals(p1, result));

        success = LibarkworksWrapper.getInstance().libarkworksAddG1(infinity, infinity, result);
        assertTrue("Addition should be successful", success);
        assertTrue("Actual result is not equal to expected", Arrays.equals(infinity, result));
    }

    @Test
    public void libarkworksMulG1() {
        byte[] x = decimalStringToBytes("3160407235063619464128567545019931358567547466670244075263201465289831140767");
        byte[] y = decimalStringToBytes("4182837998304898970040019544076242834539030974440226240296180009251026336602");
        byte[] p = concat(x, y);

        byte[] s = decimalStringToBytes("6279048861608643585519945505961201560698975384537397934874007738786214836023");

        byte[] xr = decimalStringToBytes("11506148214011837992873864028743163281598579816617145449725739769326145033132");
        byte[] yr = decimalStringToBytes("2343187880277550678705288304833947923837325393017823699197655100823437890533");
        byte[] r = concat(xr, yr);

        byte[] infinity = new byte[64];
        byte[] zero = decimalStringToBytes("0");

        byte[] result = new byte[64];
        boolean success = LibarkworksWrapper.getInstance().libarkworksMulG1(p, s, result);
        assertTrue("Multiplication should be successful", success);
        assertTrue("Actual result is not equal to expected", Arrays.equals(r, result));

        success = LibarkworksWrapper.getInstance().libarkworksMulG1(infinity, s, result);
        assertTrue("Multiplication should be successful", success);
        assertTrue("Actual result is not equal to expected", Arrays.equals(infinity, result));

        success = LibarkworksWrapper.getInstance().libarkworksMulG1(p, zero, result);
        assertTrue("Multiplication should be successful", success);
        assertTrue("Actual result is not equal to expected", Arrays.equals(infinity, result));
    }

    @Test
    public void libarkworksPairingCheck() {
        int pairs = 2;
        byte[] g1s = hexToBytes("1c76476f4def4bb94541d57ebba1193381ffa7aa76ada664dd31c16024c43f593034dd2920f673e204fee2811c678745fc819b55d3e9d294e45c9b03a76aef41111e129f1cf1097710d41c4ac70fcdfa5ba2023c6ff1cbeac322de49d1b6df7c2032c61a830e3c17286de9462bf242fca2883585b93870a73853face6a6bf411");
        byte[] g2s = hexToBytes("04bf11ca01483bfa8b34b43561848d28905960114c8ac04049af4b6315a41678209dd15ebff5d46c4bd888e51a93cf99a7329636c63514396b4a452003a35bf7120a2a4cf30c1bf9845f20c6fe39e07ea2cce61f0c9bb048165fe5e4de8775502bb8324af6cfc93537a2ad1a445cfd0ca2a71acd7ac41fadbf933c2a51be344d1800deef121f1e76426a00665e5c4479674322d4f75edadd46debd5cd992f6ed198e9393920d483a7260bfb731fb5d25f1aa493335a9e71297e485b7aef312c212c85ea5db8c6deb4aab71808dcb408fe3d1e7690c43d37b4ce6cc0166fa7daa090689d0585ff075ec9e99ad690c3395bc4b313370b38ef355acdadcd122975b");
        System.out.println(g1s.length);
        System.out.println(g2s.length);
        boolean success = LibarkworksWrapper.getInstance().libarkworksPairingCheck(g1s, g2s, pairs);
        assertTrue("Pairing check should be successful", success);
    }

    private static byte[] decimalStringToBytes(String decimal) {
        byte[] bytes = new BigInteger(decimal).toByteArray();
        return concat(new byte[32 - bytes.length], bytes);
    }

    private static byte[] hexToBytes(String hex) {
        return HexBin.decode(hex);    
    }

    private static byte[][] getG1XY(byte[] g1) {
        byte[] x = Arrays.copyOfRange(g1, 0, 32);
        byte[] y = Arrays.copyOfRange(g1, 32, 64);
        return new byte[][] { x, y };
    }

    private static byte[][] getG2ABCD(byte[] g2) {
        byte[] a = Arrays.copyOfRange(g2, 0, 32);
        byte[] b = Arrays.copyOfRange(g2, 32, 64);
        byte[] c = Arrays.copyOfRange(g2, 64, 96);
        byte[] d = Arrays.copyOfRange(g2, 96, 128);
        return new byte[][] { a, b, c, d };
    }

    private static byte[] concat(byte[] g1s, byte[] g1) {
        byte[] result = Arrays.copyOf(g1s, g1s.length + g1.length);
        System.arraycopy(g1, 0, result, g1s.length, g1.length);
        return result;
    }
}
