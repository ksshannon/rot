// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <http://unlicense.org/>

package rot

import "testing"

func TestRot(t *testing.T) {
	tests := []struct {
		in  string
		rot int
		exp string
	}{
		{"abc", 1, "bcd"},
		{"xyz", 1, "yza"},
		{"abc", 2, "cde"},
		{"abc", 3, "def"},
		{"abc", 4, "efg"},
		{"abc", 5, "fgh"},
		{"abc", 6, "ghi"},
		{"abc", 7, "hij"},
		{"abc", 8, "ijk"},
		{"abc", 9, "jkl"},
		{"abc", 10, "klm"},
		{"abc", 11, "lmn"},
		{"abc", 12, "mno"},
		{"abc", 13, "nop"},
		{"abc", 14, "opq"},
		{"abc", 15, "pqr"},
		{"abc", 16, "qrs"},
		{"abc", 17, "rst"},
		{"abc", 18, "stu"},
		{"abc", 19, "tuv"},
		{"abc", 20, "uvw"},
		{"abc", 21, "vwx"},
		{"abc", 22, "wxy"},
		{"abc", 23, "xyz"},
		{"abc", 24, "yza"},
		{"abc", 25, "zab"},
		{"abc", 26, "abc"},
		{"abc", 27, "bcd"},
		{"abc", 255, "vwx"},
		{"abc", -1, "zab"},
		{"abc", -9, "rst"},
		{"abc", -10, "qrs"},
		{"abc", -11, "pqr"},
		{"abc", -12, "opq"},
		{"abc", -13, "nop"},
		{"abc", -14, "mno"},
		{"abc", -15, "lmn"},
		{"abc", -16, "klm"},
		{"abc", -17, "jkl"},
		{"abc", -18, "ijk"},
		{"abc", -19, "hij"},
		{"abc", -20, "ghi"},
		{"abc", -21, "fgh"},
		{"abc", -22, "efg"},
		{"abc", -23, "def"},
		{"abc", -24, "cde"},
		{"abc", -25, "bcd"},
		{"abc", -26, "abc"},
		{"abc", -27, "zab"},
		{"ABC", 1, "BCD"},
		{"ABC", -1, "ZAB"},
		{"123", 1, "123"},
		{" abc", 1, " bcd"},
	}
	for _, test := range tests {
		s, err := Rotate(test.in, test.rot)
		if err != nil {
			t.Errorf("fail: %s", err)
			continue
		}
		if s != test.exp {
			t.Errorf("failed rotation: %s != %s", s, test.exp)
		}
		t.Logf("%s -> %d -> %s: PASSED\n", test.in, test.rot, s)
	}
}

func TestNil(t *testing.T) {
	_, err := Rotate("", 1)
	if err != nil {
		t.Error(err)
	}
}
