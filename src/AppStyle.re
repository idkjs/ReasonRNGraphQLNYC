open ReactNative;
module Colors = {
  let graphql = "#E535AB";
  let text = "#2d4150";
  let textDisabled = "#d9e1e8";
  let white = "#ffffff";
  let border = "#eeeeee";
  let background = "#dddddd";
  let black = "#000000";
};
let statusBarHeight = Expo.Constants.statusBarHeight->float_of_int->Obj.magic;
module AppStyle = {
  let styles =
    Style.(
      StyleSheet.create({
        "container": style(~flex=1., ~paddingTop=statusBarHeight, ()),
        "status": style(~backgroundColor=Colors.graphql, ()),
        "barStyle": style(~backgroundColor=Colors.graphql, ()),
      })
    );
};
module NavStyle = {
  let styles =
    Style.(
      StyleSheet.create({
        "tabBar":
          style(
            ~backgroundColor=Colors.white,
            ~borderTopColor=Colors.border,
            ~paddingBottom=2.->dp,
            ~paddingTop=2.->dp,
            ~marginBottom=0.->dp,
            (),
          ),
        "label": style(~fontFamily="dinMedium", ()),
        "indicator": style(~backgroundColor=Colors.graphql, ()),
      })
    );
};
module AgendaStyle = {
  let styles =
    Style.(
      StyleSheet.create({
        "container":
          style(
            ~borderRadius=3.,
            ~padding=16.->dp,
            ~paddingTop=8.->dp,
            ~marginRight=16.->dp,
            ~marginTop=32.->dp,
            ~backgroundColor=Colors.white,
            (),
          ),
        "location":
          style(
            ~fontFamily="dinMedium",
            ~fontSize=14.,
            ~marginBottom=8.->dp,
            ~color=Colors.text,
            (),
          ),
        "title":
          style(
            ~fontFamily="dinBold",
            ~fontSize=18.,
            ~marginBottom=4.->dp,
            ~color=Colors.graphql,
            (),
          ),
      })
    );
};