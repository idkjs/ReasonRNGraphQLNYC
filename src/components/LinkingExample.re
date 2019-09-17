open ReactNative;

let windowHeight = Dimensions.get(`window)##height;
let windowWidth = Dimensions.get(`window)##width;

let containerStyle =
  Style.(
    style(
      ~width=windowWidth->dp,
      ~height=windowHeight->dp,
      ~justifyContent=`center,
      ~alignItems=`center,
      (),
    )
  );

type state = {url: option(string)};

type action =
  | SetURL(option(string));

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetURL(v) => {url: v}
        },
      {url: None},
    );

  let handler = s => {
    s##url->Js.Console.warn;
  };

  let handlePromise = url =>
    Js.Promise.(
      Linking.openURL(url)
      |> then_(() => resolve(dispatch(SetURL(Some(url)))))
      |> catch(err => resolve(err->Js.Console.warn))
      |> ignore
    );

  // Listener will only receive URLs which your app is
  // registered to handle
  // https:// resource below will not be captured here
  React.useEffect0(() => {
    Linking.addEventListener(`url, handler);
    Some(() => Linking.removeEventListener(`url, handler));
  });

  <View style=containerStyle>
    <Text>
      {{Belt.Option.getWithDefault(state.url, "No URL requested")}
       ->React.string}
    </Text>
    <Button
      onPress={_ =>
        handlePromise(
          "https://github.com/reason-react-native/reason-react-native/",
        )
      }
      title="Open Repo"
    />
    // This will only work if you have registered myapp:// as
    // custom URL scheme for your app
    // Otherwise this will throw an error on the Yellow Box
    <Button
      onPress={_ => handlePromise("myapp://screen")}
      title="Internal URL"
    />
  </View>;
};
