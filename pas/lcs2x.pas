uses    math;
const   fi      ='lcs2x.inp';
        fo      ='lcs2x.out';
        oo      =trunc(1e4);

var     a, b, f :array[0..oo] of longint;
        ma,matruocj     :longint;
        ans     :longint;
        m, n    :longint;
procedure Optimize;
var     i, j    :longint;
begin
        fillchar(f, sizeof(f),0);
        for i:=1 to m do
                begin
                        ma:=0;
                        for j:=1 to n do
                                begin
                                        matruocj:=ma;
                                        if b[j]*2<=a[i] then ma:=Max(ma,f[j]);
                                        if b[j]=a[i] then f[j]:=max(f[j],matruocj+1);
                                end;
                 end;

end;

Procedure run;
var     i, t,l :longint;
begin
        assign(input,fi);assign(output,fo);
        reset(input);rewrite(output);
        readln(t);
        for l:=1 to t do
                begin
                        readln(m, n);
                        for i:=1 to m do read(a[i]);
                        for i:=1 to n do read(b[i]);
                        Optimize;
                        ans:=0;
                        for i:=1 to n do
                                if f[i]>ans then ans:=f[i];
                        writeln(ans);
                end;
        close(input);close(output);
end;

begin
        run;
end.
