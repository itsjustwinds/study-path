var
        s1,s2,s3,s4:ansistring;
        kq:int64;
procedure nhap;
begin
        readln(s1);
        readln(s2);
        readln(s3);
        readln(s4);
end;
function bd(s1,s2:ansistring):ansistring;
var
        s,nho,i:longint;
        kq:ansistring;
begin
        while length(s1)<>length(s2) do
                if length(s1)<length(s2) then s1:='0'+s1
                else if length(s1)>length(s2) then s2:='0'+s2;
        if s1<s2 then
                exit(bd(s2,s1));
        nho:=0;
        kq:='';
        for i:=length(s1) downto 1 do
        begin
                s:=ord(s1[i])-ord(s2[i])-nho;
                if s<0 then
                begin
                        s:=s+10;
                        nho:=1;
                end
                else nho:=0;
                kq:=chr(s+48)+kq;
        end;
        while (length(kq)>1)and(kq[1]='0') do delete(kq,1,1);
        exit(kq);
end;
procedure xuly;
var     t:ansistring;
begin
        kq:=0;
        while (s1<>'0') or (s2<>'0') or (s3<>'0') or (s4<>'0') do
        begin
                t:=s1;
                s1:=bd(s1,s2);
                s2:=bd(s2,s3);
                s3:=bd(s3,s4);
                s4:=bd(s4,t);
                inc(kq);
        end;
        write(kq);
end;
begin
        assign(input,'abcd.inp');
        assign(output,'abcd.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
