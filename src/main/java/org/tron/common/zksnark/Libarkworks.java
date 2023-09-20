package org.tron.common.zksnark;

class Libarkworks {
    private static final LibarkworksJNI INSTANCE = new LibarkworksJNI();

    public boolean libarkworksG1IsValid(byte[] x, byte[] y) {
        return INSTANCE.libarkworksG1IsValid(x, y);
    }
        
    public boolean libarkworksG2IsValid(byte[] a, byte[] b, byte[] c, byte[] d) {
        return INSTANCE.libarkworksG2IsValid(a, b, c, d);
    }
    
    public boolean libarkworksAddG1(byte[] a, byte[] b, byte[] result) {
        return INSTANCE.libarkworksAddG1(a, b, result);
    }
    
    public boolean libarkworksMulG1(byte[] p, byte[] s, byte[] result) {
        return INSTANCE.libarkworksMulG1(p, s, result);
    }
    
    public boolean libarkworksPairingCheck(byte[] g1s, byte[] g2s, int pairs) {
        return INSTANCE.libarkworksPairingCheck(g1s, g2s, pairs);
    }

    public void libarkworksRandomG1(byte[] g1) {
        INSTANCE.libarkworksRandomG1(g1);
    }

    public void libarkworksRandomG2(byte[] g2) {
        INSTANCE.libarkworksRandomG2(g2);
    }

    private static class LibarkworksJNI {        
        private native boolean libarkworksG1IsValid(byte[] x, byte[] y);
        
        private native boolean libarkworksG2IsValid(byte[] a, byte[] b, byte[] c, byte[] d);
        
        private native boolean libarkworksAddG1(byte[] a, byte[] b, byte[] result);
        
        private native boolean libarkworksMulG1(byte[] p, byte[] s, byte[] result);
        
        private native boolean libarkworksPairingCheck(byte[] g1s, byte[] g2s, int pairs);

        private native void libarkworksRandomG1(byte[] g1);

        private native void libarkworksRandomG2(byte[] g1);
    }
}
