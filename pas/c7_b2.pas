var     s:string;
        i,j:longint;
begin
        write('nhap chuoi:');
        readln(s);
        for i:=1 to length(s) do
                if s[i] in ['A'..'Z'] then
                       s[i]:=chr(ord(s[i])+32);
        write(s);
        readln
end.