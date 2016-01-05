package test

import engine.core.{Engine, NativesLoader}

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Main {
  def main(args: Array[String]) {
    NativesLoader.load()
    Engine.start()
  }
}
